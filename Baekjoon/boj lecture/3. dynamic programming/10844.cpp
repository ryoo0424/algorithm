#include<cstdio>
long long d[101][10];
int main(){
	int n;
	scanf("%d", &n);
	for (int i=1; i<10; i++) d[1][i] = 1;
	for (int j=2; j<=n; j++) {
		for (int k=0; k<9; k++) d[j][k] += d[j-1][k+1];
		for (int k=1; k<=9; k++) d[j][k] += d[j-1][k-1];
		for (int k=0; k<10; k++) d[j][k] %= 1000000000;
		}
	long long ans = 0;
	for (int i=0; i<10; i++) ans += d[n][i];
	printf("%lld", ans % 1000000000);
	return 0;
}
/*
d[i][j] = d[i-1][j-1] + d[i-1][j+1] (1<=j<=8)
d[i][9] = d[i-1][8]
d[i][0] = d[i-1][1]
*/





/*
d[n][l]: n자리 계단수의 마지막 수 l
n-1자리 : l-1 or l+1 --> n자리 : l (1<=l<=8)
d[n][0] = d[n-1][1] (l=0)
d[n][9] = d[n-1][8] (l=9)
*/
