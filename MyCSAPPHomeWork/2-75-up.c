#include<stdio.h>
#include<stdint.h>
#include<stdio.h>
typedef unsigned char *byte_pointer;
int32_t signed_high_prod(int32_t x,int32_t y);
int32_t signed_high_prod(int32_t x,int32_t y){
	int64_t mul = (int64_t) x * y;
	int result;
	result = (int32_t)(mul >> 32);
	return result;
}

uint32_t unsigned_high_prod(uint32_t x,uint32_t y){
	uint32_t result;
	uint32_t t_high=(uint32_t)signed_high_prod((int) x,(int) y);
	result=t_high+((x>>31)*y)+((y>>31)*x);
	return result;
}

void show_bytes(byte_pointer start,size_t len){
	size_t i;
	for(i=len-1;i>0;i--)
		printf("%.2x",start[i]);
	printf("%.2x",start[0]);
	printf("\n");
}
void main(){
	uint32_t result;
	uint32_t x=0x3039;
	uint32_t y=0xfffff6f7;
	result=unsigned_high_prod(x,y);
	show_bytes((byte_pointer) &result,sizeof(uint32_t));
}
