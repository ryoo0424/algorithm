#include<iostream>
using namespace std;
long long d[1001][10];
int mod = 10007; 
int main(){
	int n;
	cin >> n;
	for (int i=0; i<10; i++) d[1][i] = 1;
	for (int i=2; i<=n; i++) {
		for (int j=0; j<10; j++) {
			for (int k=0; k<=j; k++) {
			d[i][j] += d[i-1][k];
			}
			d[i][j] %= mod;
		}
	}
	int ans = 0;
	for (int i=0; i<10; i++) ans += d[n][i];
	cout << ans % mod << endl;
	return 0;
}
/*
d[n][l]: n번째 자리의 마지막 수 l
d[n][l] = d[n-1][0] ~ d[n-1][l]
*/

