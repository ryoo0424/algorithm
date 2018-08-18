#include<iostream>
#include<algorithm>
#define MAX(x,y,z) ((x>y?x:y)>(y>z?y:z)?(x>y?x:y):(y>z?y:z))
using namespace std;
int d[10001][3];
int wine[10001];
int main(){
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) cin >> wine[i];
	d[1][0] = 0, d[1][1] = wine[1], d[1][2] = wine[1];
	for (int i=2; i<=n; i++) {
		d[i][0] = MAX(d[i-1][0], d[i-1][1], d[i-1][2]);
		d[i][1] = d[i-1][0] + wine[i];
		d[i][2] = d[i-1][1] + wine[i];
	}
	cout << MAX(d[n][0], d[n][1], d[n][2]);
	return 0;	
}
/*
d[n][i]: n번째 잔이 i번째 연속잔
d[n][0](마시지 않는 경우) = max(d[n-1][2]~~~)
d[n][1](처음으로 마시는 잔인 경우) = d[n-1][0] + wine[n]
d[n][2](두 잔 째 연속으로 마시는 경우) = d[n-1][1] + wine[n]

*/
