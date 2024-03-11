#include <stdio.h>
void printBinary(unsigned int num);
int leftmost_one(unsigned x) {
printBinary(x);
x |= x >> 1;
printBinary(x);
x |= x >> 2;
printBinary(x);
x |= x >> 4;
printBinary(x);
x |= x >> 8;
printBinary(x);
x |= x >> 16;
printBinary(x);
/*
* then, do (mask >> 1) + (mask && 1), in which mask && 1 deals with case x = 0, rese
rve leftmost bit one
* that's we want
*/
return (x >> 1) + (x && 1);
}
void printBinary(unsigned int num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        if ((num >> i) & 1)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}
void main() {
	unsigned val;
	int x;
	printf("number:\n");
	scanf("%x",&val);
	x=leftmost_one(val);
	printf("%x",x);
}
