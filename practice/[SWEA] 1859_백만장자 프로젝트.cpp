#include <iostream>
using namespace std;

long long a[1000001];
bool check[1000001];

int main() {
	int t;	cin >> t;
	for (int x=1; x<=t; x++) {
		int max = 0;
		int n;	cin >>n;
		
		for (int i=0; i<n; i++) cin >> a[i];
		
		for (int i=n-1; i>=0; i--) {
			if (a[i] > max) {
				max = a[i];
				check[i] = true;
			} else {
				check[i] = false;
			}
		}
		
		int cnt = 0, idx = 0;
		long long gain = 0;
		
		while (idx < n) {
			while (!check[idx]) {
				gain -= a[idx++];
				cnt += 1;
			}
			gain += cnt * a[idx++];
			cnt = 0;
		}
		
		cout << "#" << x << " " << gain << '\n';
	}
	return 0;
}
