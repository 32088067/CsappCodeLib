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
	uint32_t w=sizeof(uint32_t);
	uint32_t t_high=(uint32_t)signed_high_prod((int) x,(int) y);
	result=t_high+((x>>(w-1))*y)+((y>>(w-1))*x);
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
	int64_t mul;
	uint64_t umul;
	int32_t x;
	int32_t y;
	printf("signed x:\n");
	scanf("%d",&x);
	printf("signed y:\n");
	scanf("%d",&y);
	uint32_t ux=(uint32_t)x;
	uint32_t uy=(uint32_t)y;
	printf("x=");
	show_bytes((byte_pointer) &x,sizeof(int32_t));
	printf("y=");
	show_bytes((byte_pointer) &y,sizeof(int32_t));
	printf("ux=");
	show_bytes((byte_pointer) &ux,sizeof(uint32_t));
	printf("uy=");
	show_bytes((byte_pointer) &uy,sizeof(uint32_t));
	mul = (int64_t) x * y;
	printf("mul=");
	show_bytes((byte_pointer) &mul,sizeof(int64_t));
	umul = (uint64_t) ux * uy;
	printf("umul=");
	show_bytes((byte_pointer) &umul,sizeof(uint64_t));
	int32_t high_mul=(int32_t)(mul>>32);
	uint32_t high_umul=(uint32_t)(umul>>32);
	printf("high_mul:");
	show_bytes((byte_pointer) &high_mul,sizeof(int32_t));
	printf("high_umul:");
	show_bytes((byte_pointer) &high_umul,sizeof(uint32_t));
}
