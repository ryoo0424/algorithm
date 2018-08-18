#include<iostream>
using namespace std;
int main(void){
	int n;
	scanf("%d", &n);
	for (int i=n-1; i>=0; i--){
		for (int j=i; j<n; j++) printf("*");
		for (int k=i; k>0; k--) printf(" ");
		for (int k=i; k>0; k--) printf(" ");
		for (int j=i; j<n; j++) printf("*");
		puts("");
	}
	for (int i=1; i<=n-1; i++){
		for (int j=n-i; j>0; j--) printf("*");
		for (int k=n-i; k<n; k++) printf(" ");
		for (int k=n-i; k<n; k++) printf(" ");
		for (int j=n-i; j>0; j--) printf("*");
		puts("");
	}
	return 0;
}
