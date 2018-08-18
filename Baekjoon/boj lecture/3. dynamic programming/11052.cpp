#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int d[1001];
int p[1001];
int main(){
	// d[n]: n개 팔아서 얻을 수 있는 최대 수익 
	// (@ + @ + @ + ...):d[n-1] + @(p[1]) = n
	// ==> d[i] = max(p[i] + d[n-i]): 1<=i<=n
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", &p[i]);
	d[1] = p[1];
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=i; j++) {
			d[i] = max(d[i], p[j] + d[i-j]);	
		}
	}
	printf("%d\n", d[n]);
	return 0;
}
