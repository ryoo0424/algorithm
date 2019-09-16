#include <iostream>
#include <cstdio>
using namespace std;
double calc(double n, int m, double p, double mid) {
	double ret = n;
	for (int i=0; i<m; i++) ret = ret*(1.0+(p/1200.0))-mid;
	return ret;
}
int main() {
	int t;	cin >> t;
	while (t--) {
		double n, p;
		int m;
		cin >> n >> m >> p;
		double left = 0, right = n*(1.0+(p/1200.0)), mid;
		for (int j=0; j<100; j++) {
			double mid = left + (right - left) / 2;
			if (calc(n, m, p, mid) > 0) left = mid;
			else if (calc(n, m, p, mid) < 0) right = mid;
			else {
				printf("%.10lf\n", mid);
				break;
			}
		}
	}
	return 0;
}
