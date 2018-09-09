#include<cstdio>
int a[10001];
int main() {
	int n, tmp;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &tmp);
		a[tmp] += 1;		
	}
	for (int i=0; i<=10000; i++) {
		if (a[i] > 0) {
			for (int j=0; j<a[i]; j++) printf("%d\n", i);
		}
	}
	return 0;	
}
