#include<stdio.h>

unsigned rotate_left(unsigned x,int n){
	int w=(sizeof(unsigned))<<3;
	int m=w-n;
	return x<<n|x>>(w-n-1)>>1;
}

void main(){
	unsigned x;
	int n;
	printf("x:\n");
	scanf("%x",&x);
	printf("n:\n");
	scanf("%d",&n);
	x=rotate_left(x,n);
	printf("n=%d -> 0x%x\n",n,x);
	
}
