#include<stdio.h>

unsigned floatScale2(unsigned uf) {
  	unsigned sign=0;
	unsigned exp=0;
	unsigned mantissa=0;
	unsigned result=0;
	sign=(uf>>31)&0x1;
	exp=(uf>>23)%0xff;
	mantissa=uf%(0x800000);
	if((exp==0xff)&&(mantissa!=0)){
		return uf;
}
	if(exp!=0xff)
		exp+=1;
	result=sign;
	result<<=1;
	result+=exp;
	result<<=23;
	if(exp==0xfe){
		mantissa=0;
	}
	result+=mantissa;
	return result;
}

void main(){
	unsigned val;
	printf("val:\n");
	scanf("%x",&val);
	printf("(float)val:%f\n",(float)val);
	val=floatScale2(val);
	printf("val:%u\n",val);
	printf("(float)val:%f\n",(float)val);
}
