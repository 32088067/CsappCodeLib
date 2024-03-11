#include<stdio.h>
int isLessOrEqual(int x, int y) {
	int sx=x>>31;
	int sy=y>>31;
	int flag1=(!(x^y));
	int flag2=sx&(!sy);
	int flag3=!!((x+(~y+1))>>31);
	int flag4=((!sx)&(!sy))&flag3;
	int flag5=(sx&sy)&flag3;
	return flag1|flag2|flag4|flag5;
}
void main(){
	int x=-2147483648;
	int y=-1917963177;
	int flag=isLessOrEqual(x,y);
	printf("flag=%d\n",flag);
	if(flag)
		printf("x<=y\n");
	else
		printf("x>y\n");
}
