#include<stdio.h>
#include<limits.h>
int saturating_add(int x,int y){
	int sum=x+y;
	int sig_mask=INT_MIN;
	int pos_overflow=!(x&sig_mask)&&!(y&sig_mask)&&(sum&sig_mask);
	int neg_overflow=(x&sig_mask)&&(y&sig_mask)&&!(sum&sig_mask);
	(pos_overflow&&(sum=INT_MAX)||neg_overflow&&(sum=INT_MIN));
	return sum;
}

void main(){
	int x=0;
	int y=0;
	int sum=0;
	printf("x:\n");
	scanf_s("%d",&x);
	printf("y:\n");
	scanf_s("%d",&y);
	sum=saturating_add(x,y);
	printf("sum=%d\n",sum);
}
