#include<iostream>
using namespace std;
int main(void){
	int n;
	scanf("%d", &n);
	for (int i=n-1; i>=0; i--){
		for (int j=0; j<i; j++) printf(" ");
		for (int k=1; k<=2*(n-i)-1; k++) printf("*");
		puts("");
	}
	for (int i=0; i<n-1; i++){
		for (int j=0; j<=i; j++) printf(" ");
		for (int k=2*(n-1-i)-1; k>0; k--) printf("*");
		puts("");
	}
	return 0;
}
