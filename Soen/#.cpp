#include<stdio.h>
#include<stdlib.h>
// #과 ## 모두 #define 문 내에서만 사용됨 
#define BIN(a) strtol(# a, NULL, 2)
#define var(a, b) (a##b)
#define defPType(type) typedef type *p##type

int main(void)
{
	// 1. single sharp operation - binary const
	printf("%x\n", BIN(00010010001101001111000001011100));
	// 2. double sharp operation
	int var(Total, Score);
	TotalScore = 256;
	printf("total score = %d\n", TotalScore);
	// 3. define type
	defPType(int);
	pint pi;
	int i = 3;
	pi = &i;
	printf("i = %d\n", *pi);
	
	return 0;
}
