#include<iostream>
using namespace std;
int a[100000], d[100000]; 
int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	int ans = d[0] = a[0];
	for (int i=1; i<n; i++) {
		d[i] = a[i];
		if (d[i] < d[i-1] + a[i]) d[i] = d[i-1] + a[i];
		if (ans < d[i]) ans = d[i];
	}
	cout << ans << endl;
	return 0;
}
/*
d[i] = a[i]로 끝나는 최대 연속합
1. a[i-1]로 끝나는 연속합이 포함: d[i-1] + a[i]
2. 새로운: a[i] 
# 1, 2 중 큰 수를 선택 
*/
