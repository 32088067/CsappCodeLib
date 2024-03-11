#include<stdio.h>
#include<limits.h>
void main(){
	int x=-21;
	int y=2;
	unsigned int ux=(unsigned int) x;
	unsigned int uy=(unsigned int) y;
	if((ux-uy)==-(unsigned) (y-x))
		printf("1\n");
	else
		printf("0\n");
}
