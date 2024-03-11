#include<stdio.h>
#include<stdbool.h>

bool int_shifts_are_arithmetic(){
	int x=-1;
	if(x>>((sizeof(int)<<3)-1)==-1){
		printf("This machine shifts are arithmetic!\n");
		return 1;
	}
	else if(x>>((sizeof(int)<<3)-1)==1){
		printf("This machine shifts are logic!\n");
		return 0;
	}
}

bool main(){
	return int_shifts_are_arithmetic();
}
