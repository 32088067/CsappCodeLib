#include<stdio.h>

int fits_bits(int x,int n){
	printf("x:%x\n",x);
	int mask=((1<<n)-1)&x;
	printf("x:%x\n",x);
	printf("mask:%x\n",mask);
	return !(mask^x);
}

void main(){
	int x;
	int n;
	int result;
	printf("x:(0x)\n");
	scanf("%x",&x);
	printf("n:\n");
	scanf("%d",&n);
	result=fits_bits(x,n);
	printf("Result:%d\n",result);
}
