#include<cstdio>
int main(void){
	int n;
	scanf("%d", &n);
	
	for (int i=0; i<n-1; i++) printf(" ");
	printf("*\n");
	if (n == 1) return 0;
	for (int i=n-2; i>0; i--) {
		for (int j=i; j>0; j--) printf(" ");
		printf("*");
		for (int k=1; k<=2*(n-1-i)-1; k++) printf(" ");
		printf("*\n");
	} 
	
	for (int i=0; i<2*n-1; i++) printf("*");
	puts("");
	return 0;
}
