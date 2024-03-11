#include<stdio.h>

typedef unsigned char *byte_pointer;

int is_little_endian(){
	int val=0xff;
	byte_pointer start=(byte_pointer)&val;
	if(start[0]==0xff)
		return 1;
	else
		return 0;
}

void main(){
	if(is_little_endian()==0)
		printf("Big Endian!\n");
	else
		printf("Little Endian!\n");
}
