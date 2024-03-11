#include<stdio.h>
#include<assert.h>
#include<math.h>
typedef unsigned float_bits;
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start,size_t len){
	size_t i;
	for(i=0;i<len;i++)
		printf("%.2x",start[i]);
	printf("\n");
}

void show_float(float x){
	show_bytes((byte_pointer) &x,sizeof(float));
}

void show_float_bits(float_bits x){
	show_bytes((byte_pointer) &x,sizeof(float_bits));
}
float_bits float_negate(float_bits f){
	unsigned neg_sign=(f>>31)^0x1;
	unsigned exp=(f>>23)&0xFF;
	unsigned frac=f&0x7FFFFF;
	if(exp==0xFF&&frac!=0)
		return f;
	return (neg_sign<<31)|(exp<<23)|frac;	
}

void main(){
	float val=sqrt(-1);
	float negate_val=-val;
	show_float(val);
	show_float(negate_val);
	float_bits x=0x7F823123;
	show_float_bits(float_negate(x));
	//assert(float_negate(val1)==(-val1));	
	return;
}
