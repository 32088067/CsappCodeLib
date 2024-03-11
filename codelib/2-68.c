#include<stdio.h>
typedef unsigned char *byte_pointer;
int lower_one_mask(unsigned n){
	int val=(1<<n)-1;
	return val;
}

void show_bytes(byte_pointer start,int len){
	int i;
	for(i=len-1;i>=0;i--)
		printf("%.2x",start[i]);
	printf("\n");
}
void main(){
	unsigned n;
	int mask;
	printf("n:\n");
	scanf("%u",&n);
	mask=lower_one_mask(n);
	show_bytes((byte_pointer) &mask,sizeof(int));
	
}
