#include<stdio.h>
#include<limits.h>
int tsub_ok(int x,int y){
	int val=x-y;
	if(x>0){
		if(y<0){
			if(val<0)
				return 0;
			else
				return 1;
		}
		else
			return 1;
	}
	else if(x==0){
		if(y!=INT_MIN)
			return 1;
		else
			return 0;
	}
	else{
		if(y>0){
			if(val>0)
				return 0;
			else
				return 1;
		}
		else
			return 1;
	}
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
