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
float_bits float_i2f(int i){
	unsigned sign=(i>>31)&0x1;
	if(sign)
		i=~i+1;		//i2u,pay attention to T_MIN;
	unsigned mask=i;
	mask|=mask>>1;
	mask|=mask>>2;
	mask|=mask>>4;
	mask|=mask>>8;
	mask|=mask>>16;
	//或运算，把int整数的二进制变成最高位形式的全1,
	//例如，1101101=1111111,10100=11111
	int lefmos=0;
	while(mask!=0){
		lefmos+=mask&1;
		mask>>=1;
	}
	//循环相加，lefmos即为int类型i的最高有效位
	unsigned exp=0;
	unsigned frac=0;
	if(lefmos==0)
		return sign<<31;
	//Be Normalized
	else if(lefmos>=1&&lefmos<=24){
		exp=127+lefmos-1;
		frac=(i<<(24-lefmos))&0x7FFFFF;
	}
	else if(lefmos>24&&lefmos<32){
		exp=127+lefmos-1;
		frac=(i>>(lefmos-24))&0x7FFFFF;
	}
	else if(lefmos==32){
		exp=127+lefmos-1;
		frac=0;
	}
	return (sign<<31)|(exp<<23)|frac;
}

void main(){
	FloatIntUnion val;
	int i=2147483647;
	printf("i:%d\n",i);
	printf("(float)i:%f\n",(float)i);
	val.u=float_i2f(i);
	printf("i2f:%f\n",val.f);
	

	FloatIntUnion TMax2F;
	int INT_MAX=0x7FFFFFFF;
	TMax2F.f=(float)INT_MAX;
	printf("INT_MAX:\t%d\n",INT_MAX);
	printf("INT_MAX(HexaDecimal):\t%x\n",INT_MAX);
	printf("TMax2F:\t%f\n",TMax2F.f);
	printf("TMax2F Bit Level:\t%x\n",TMax2F.u);
	assert(val.f==(float)i);
}




