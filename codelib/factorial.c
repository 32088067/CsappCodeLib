#include<stdio.h>
int tmult_ok(int x,int y){
	int p=x*y;
	return !x || p/x==y;
}

void main(){
	int n;
	int result=1;
	printf("n:\n");
	scanf("%d",&n);
	do{
		if(tmult_ok(result,n))
			result*=n;
		else{
			printf("overflow!\n");
			return;
		}
		n--;
	}while(n>1);
	printf("result=%d\n",result);
}
