#include<stdio.h>
#include<stdbool.h>
void main(){
	int x;
	printf("type a number(0x):\n");
	scanf("%x",&x);
	if(!((x&0xFF)-0xFF))
		printf("low byte is FF!\n");
	else
		printf("low byte is'nt FF!\n");
	bool y;
	y=!(((x>>((sizeof(int)-1)<<3)))&0xFF);
	if(y)
		printf("hign byte is 00!\n");
	else
		printf("hign byte is'nt 00!\n");

}
