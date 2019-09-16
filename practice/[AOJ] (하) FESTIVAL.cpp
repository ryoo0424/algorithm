#include <iostream>
using namespace std;
int a[1000];
int main() {
	int t;	cin >> t;
	while (t--) {
		int n, l;	cin >> n >> l;
		for (int i=0; i<n; i++) cin >> a[i];
		double ans = 100000;
		for (int i=0; i<n; i++) {
			int sum = 0;
			for (int j=i; j<n; j++) {
				sum += a[j];
				double cmp = (double)sum/(j-i+1);
				if (j-i+1 >= l && ans > cmp) ans = cmp;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
