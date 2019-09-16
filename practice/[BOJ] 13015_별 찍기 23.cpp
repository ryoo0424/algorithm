#include <iostream>
using namespace std;

int main() {
	int n;	cin >> n;
	// first line 
	for (int i=0; i<n; i++) printf("*");
	for (int i=0; i<n*2-3; i++) printf(" ");
	for (int i=0; i<n; i++) printf("*");
	puts("");
	// upper middle & center
	for (int i=1; i<n; i++) {
		for (int j=0; j<i; j++) printf(" ");
		printf("*"); for (int j=1; j<n-1; j++) printf(" "); printf("*");
		for (int j=0; j<(n-i)*2-3; j++) printf(" ");
		if (i < n-1) printf("*"); for (int j=1; j<n-1; j++) printf(" "); printf("*");
		puts("");
	}
	// lower middle
	for (int i=n-2; i>0; i--) {
		for (int j=0; j<i; j++) printf(" ");
		printf("*"); for (int j=1; j<n-1; j++) printf(" "); printf("*");
		for (int j=0; j<(n-i)*2-3; j++) printf(" ");
		if (i < n-1) printf("*"); for (int j=1; j<n-1; j++) printf(" "); printf("*");
		puts("");
	}
	// last line 
	for (int i=0; i<n; i++) printf("*");
	for (int i=0; i<n*2-3; i++) printf(" ");
	for (int i=0; i<n; i++) printf("*");
	puts("");
	
	return 0;
}
