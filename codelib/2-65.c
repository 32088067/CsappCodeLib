#include<stdio.h>

int odd_ones(unsigned x){
	x^=x>>16;
	printf("%x\n",x);
	x^=x>>8;
	printf("%x\n",x);
	x^=x>>4;
	printf("%x\n",x);
	x^=x>>2;
	printf("%x\n",x);
	x=x>>1;
	printf("%x\n",x);
	return x&1;
}

void main(){
	unsigned val;
	printf("number:\n");
	scanf("%d",&val);
	printf("%x\n",val);
	if(odd_ones(val))
		printf("1\n");
	else
		printf("0\n");
	
	
}

