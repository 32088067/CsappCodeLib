#include<stdio.h>

int howManyBits(int x) {
	int sign=(x>>31)&1;   //get x sign bit
	sign=~sign+1;	//turn logic to all0 or all1
	int negx=(~x)+1;
	int mask=(~sign&x)|(sign&negx);
	printf("x mask: %x\n",mask);
	mask|=(mask>>1);
	mask|=(mask>>2);
	mask|=(mask>>4);
	mask|=(mask>>8);
	mask|=(mask>>16);
	printf("x mask: %x\n",mask);
	int sum=1;
	for(int i=0;i<31;i++){
		mask>>=1;
		sum+=mask&1;
	}
	return sum;
}

void main(){
	int x;
	printf("x:\n");
	scanf("%d",&x);
	printf("hexadecimal x: %x\n",x);
	int bit=howManyBits(x);
	printf("x has %d bits\n",bit);
}
