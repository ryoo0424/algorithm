#include <iostream>
using namespace std;
long long ratio(long long n, long long m) {
	return (m*100)/n;
}
int main() {
	int t;	cin >> t;
	while (t--) {
		long long n, m;	cin >> n >> m;
		long long left = 0, right = 2e+9, mid;
		if (ratio(n, m) == ratio(n+right, m+right)) {
			cout << "-1\n";
			continue;
		}
		for (int i=0; i<100; i++) {
			mid = left + (right - left) / 2;
			if (ratio(n, m) == ratio(n+mid, m+mid)) left = mid;
			else right = mid;
		}
		cout << mid+1 << '\n'; // mid+1 : (left+right)/2면 항상 1 작은 값이 나오기 때문 
	}
	return 0;
}
