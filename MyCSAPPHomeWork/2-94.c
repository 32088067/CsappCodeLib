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
float_bits float_twice(float_bits f){
	unsigned sign=f&0x80000000;
	unsigned exp=(f>>23)&0xFF;
	unsigned frac=f&0x7FFFFF;
	if(exp==0xFF)
		return f;
	if(exp==0&&frac==0)
		return 0;
	else if(exp==0&&frac<0x400000)
	//denormalized
		frac=(frac<<1)&0x7FFFFF;
	else if(exp==0&&frac>=0x400000){
		frac=(frac<<1)&0x7FFFFF;
		exp=1;	
	}
	else if(exp<0xFE)
		++exp;
	else{
		++exp;
		frac=0;
	}
	return sign|(exp<<23)|frac;	
}

void main(){
	FloatIntUnion val;
	val.u=0x003571FF;
	float compare=val.f;
	printf("u=%x\n",val.u);
	printf("u2f=%.50f\n",val.f);
	val.u=float_twice(val.u);
	printf("2.0*f=%.50f\n",2.0*compare);
	printf("float_twice(f)=%.50f\n",val.f);
	assert(val.f==2.0*compare);	
	return;
}
