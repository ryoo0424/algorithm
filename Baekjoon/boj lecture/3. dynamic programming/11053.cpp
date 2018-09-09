#include<iostream>
using namespace std;
int d[1000], a[1000];
int main(){
	int n, ans = 1;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++) {
		d[i] = 1;
		for (int j=i-1; j>=0; j--) {
			if (a[j] < a[i] && d[j] >= d[i]) d[i] = d[j] + 1;
			if (ans < d[i]) ans = d[i];
		}
	}
	cout << ans << endl;
	return 0;
}
/*


*/

/*
d[i] = a[1], ... , a[i]까지의 수열이 있을 때 a[i]를 마지막으로 하는
가장 긴 증가하는 부분 수열의 길이 
d[i]는 a[i]가 반드시 포함되어야 한다
d[i] = max(d[j]) + 1, j<i, a[j] < a[i] 
*/
