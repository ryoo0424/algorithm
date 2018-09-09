#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int d[1000], d2[1000];
int main(){
	int n, ans = 0;
	cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++) {
		d[i] = 1;
		for (int j=0; j<i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1) d[i] = d[j] + 1;
		}
	}
	reverse(a.begin(), a.end());
		for (int i=0; i<n; i++) {
		d2[i] = 1;
		for (int j=0; j<i; j++) {
			if (a[j] < a[i] && d2[i] < d2[j] + 1) d2[i] = d2[j] + 1;
		}
	}
	for (int i=0; i<n; i++) if (d[i] + d2[i] - 1 > ans) ans = d[i] + d2[i] - 1;
	cout << ans << endl;
	return 0;
}
