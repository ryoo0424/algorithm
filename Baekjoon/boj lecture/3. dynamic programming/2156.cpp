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
d[n][i]: n��° ���� i��° ������
d[n][0](������ �ʴ� ���) = max(d[n-1][2]~~~)
d[n][1](ó������ ���ô� ���� ���) = d[n-1][0] + wine[n]
d[n][2](�� �� ° �������� ���ô� ���) = d[n-1][1] + wine[n]

*/
