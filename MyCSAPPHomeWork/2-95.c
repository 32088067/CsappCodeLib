#include<stdio.h>
#include<assert.h>
#include<math.h>
typedef unsigned float_bits;
typedef unsigned char *byte_pointer;

typedef union{
	float f;
	unsigned int u;
}FloatIntUnion;
void show_bytes(byte_pointer start,size_t len){
	size_t i;
	for(i=0;i<len;i++)
		printf("%.2x",start[i]);
	printf("\n");
}

void show_float(float x){
	show_bytes((byte_pointer) &x,sizeof(float));
}

void show_float_bits(float_bits x){
	show_bytes((byte_pointer) &x,sizeof(float_bits));
}
float_bits float_half(float_bits f){
	unsigned sign=f&0x80000000;
	unsigned exp=(f>>23)&0xFF;
	unsigned frac=f&0x7FFFFF;
	unsigned addition=(frac&0x3==0x3);
	if(exp==0xFF)
		return f;
	if(exp==0&&frac==0)
		return 0;
	else if(exp==0&&frac==1)
		return 0;
	else if(exp==0&&frac>1){
	//denormalized
	//round to even
	//00->0 just >> 1
	//01->0 just >> 1
	//10->1 just >> 1
	//11->1+1 (>>1 and +1)
		frac>>=1;
		frac+=addition;
	}
	else if(exp==1){
	//Normalized to Denorm
		unsigned rest=f&0x7fffffff;
		rest>>=1;
		rest+=addition;
		exp=rest>>23;
		frac=rest&0x7FFFFF;
	}
	else{
		--exp;
	}
	return sign|(exp<<23)|frac;
}

void main(){
	FloatIntUnion val;
	val.u=0x008571FF;
	float compare=val.f;
	printf("u=\t%x\n",val.u);
	printf("u2f=\t%.50f\n",val.f);
	val.u=float_half(val.u);
	printf("0.5*f=\t%.50f\n",0.5*compare);
	printf("float_half(f)=\t%.50f\n",val.f);
	assert(val.f==0.5*compare);	
	return;
}
