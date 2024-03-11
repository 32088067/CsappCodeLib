#include<stdio.h>

void main(){
	int x;
	int y;
	int z;
	printf("please type Number x\n");
	scanf("%d",&x);
	printf("please type Number y\n");
	scanf("%d",&y);
	printf("%X\n",x);
	printf("%X\n",y);
	x=x&0xff;
	y=y>>8;
	y=y<<8;
	z=x|y;
	printf("%X\n",x);
	printf("%X\n",y);
	printf("%X\n",z);
}
