#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int a[100];
	int op[4];
	int order[99];
	int cnt = 0, n;	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<4; i++) cin >> op[i];
	for (int i=0; i<4; i++) {
		for (int j=0; j<op[i]; j++) {
			order[cnt++] = i;
		}
	}
	sort(order, order+cnt);
	int MAX = -1987654321;
	int MIN = -MAX;
	do {
		int result = a[0];
		for (int i=0; i<n-1; i++) {
			if (order[i] == 0) result += a[i+1];
			else if (order[i] == 1) result -= a[i+1];
			else if (order[i] == 2) result *= a[i+1];	
			else result /= a[i+1];
		}
		if (MAX < result) MAX = result;
		if (MIN > result) MIN = result;
	} while (next_permutation(order, order+cnt));
	cout << MAX << '\n' << MIN << '\n';
	return 0;
}
