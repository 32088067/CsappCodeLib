#include<stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b){
	unsigned val=(unsigned) b;
	unsigned num=~(0xff);
	val=val<<(i*8);
	num=num<<(i*8);
	num=num+((1<<(i*8))-1);
	x=(x&num)|val;
	return x;
}

void main(){
	unsigned x;
	int i;
	unsigned char b;
	printf("unsigned x\n");
	scanf("%X",&x);
	printf("int i:\n");
	scanf("%d",&i);
	printf("unsigned char b:\n");
	scanf("%hhx",&b);
	unsigned val;	
	val=replace_byte(x,i,b);
	printf("replace_byte(%08x,%d,%hhx) --> %08x\n",x,i,b,val);
}
