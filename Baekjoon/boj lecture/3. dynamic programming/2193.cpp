#include<cstdio>
long long d[91];
int main(void){
	d[1] = 1;
	d[2] = 1;
	int n;
	scanf("%d", &n);
	if (n <= 2) printf("%d\n", d[n]);
	else {
		for (int i=3; i<=n; i++) d[i] = d[i-1] + d[i-2];
		printf("%lld\n", d[n]);
	}
	return 0;
}
/*
d[n] = d[n-1](마지막이 0인 경우) 
d[n] = d[n-2](마지막이 1인 경우 이전에 0이어야 하므로 d[n-1] = d[n-2]) 
*/
