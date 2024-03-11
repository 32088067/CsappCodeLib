#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start,size_t len){
	size_t i;
	for(i=0;i<len;i++)
		printf("%.2x",start[i]);
	printf("\n");
}

void show_int(int x){
	show_bytes((byte_pointer) &x,sizeof(int));
}

void show_float(float x){
	show_bytes((byte_pointer) &x,sizeof(float));
}

void show_pointer(void *x){
	show_bytes((byte_pointer) &x,sizeof(void *));
}

void show_short(short x){
	show_bytes((byte_pointer) &x,sizeof(short));
}

void show_long(long x){
	show_bytes((byte_pointer) &x,sizeof(long));
}

void show_double(double x){
	show_bytes((byte_pointer) &x,sizeof(double));
}

void test_show_bytes(int val){
	int ival=val;
	float fval=(float) ival;
	short sval=(short) ival;
	long lval=(long) ival;
	double dval=(double) ival;
	int *pval=&ival;
	show_int(ival);
	show_short(sval);
	show_long(lval);
	show_float(fval);
	show_double(dval);
	show_pointer(pval);
}
int main(){
	int x=0;
	printf("Please type a int number:\n");
	scanf("%d",&x);
	test_show_bytes(x);
	return 0;
}
