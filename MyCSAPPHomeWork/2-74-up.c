#include<stdio.h>
#include<limits.h>
int tsub_ok(int x,int y){
	int rax=1;
	int sub=x-y;
	int neg_overflow=x<0&&y>0&&sub>0;
	int pos_overflow=x>0&&y<0&&sub<0;
	rax=rax&&!(neg_overflow||pos_overflow);
	return rax;
}

void main(){
	int x;
	int y;
	int flag;
	printf("x:\n");
	scanf("%d",&x);
	printf("y:\n");
	scanf("%d",&y);
	flag=tsub_ok(x,y);
	printf("x-y=%d\n",x-y);
	if(flag==1)
		printf("not overflow!\n");
	else
		printf("overflow!\n");
	
}
