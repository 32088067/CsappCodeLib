#include<stdio.h>

int any_odd_one(unsigned x){
	unsigned mask=0xAAAAAAAA;
	return !(!(mask&x));
}

void main(){
	unsigned val;
	printf("number:\n");
	scanf("%d",&val);
	printf("%x\n",val);
	if(any_odd_one(val))
		printf("1\n");
	else
		printf("0\n");
	
	
}

