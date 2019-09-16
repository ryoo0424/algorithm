#include <iostream>

using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

bool next_permutation(int a[9]) {
	int i = 8, j = 8;
	while (a[i-1] > a[i]) i--;
	if (i < 2) return false;
	while (a[j] < a[i-1]) j--;
	swap(a[i-1], a[j]);
	j = 8;
	while (i < j) swap(a[i++], a[j--]);
	return true;
}

int main() {
	int tmp[9];
	int order[9] = {3, 0, 1, 2, 4, 5, 6, 7, 8};
	int result[50][9];
	
	int n;	cin >> n;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<9; j++) {
			cin >> result[i][j];
		}
	}
	
	int ans = 0;
	
	do {
		int sum = 0, hitter = 0;
		
		for (int inn=0; inn<n; inn++) {
			int out = 0;
			int base[3] = {0, };
			
			for (int i=0; i<9; i++) {
				tmp[order[i]] = result[inn][i];
			}
			
			while (out < 3) {
				int now = tmp[hitter++];
				
				if (hitter > 8) hitter %= 9;
				
				if (now == 0) {
					if (out == 2) break;
					out += 1;
				} else if (now == 1) {
					sum += base[2];
					base[2] = base[1];
					base[1] = base[0];
					base[0] = 1;
				} else if (now == 2) {
					sum += base[2] + base[1];
					base[2] = base[0];
					base[1] = 1;
					base[0] = 0;
				} else if (now == 3) {
					sum += base[2] + base[1] + base[0];
					base[2] = 1;
					base[1] = 0;
					base[0] = 0;
				} else {
					sum += base[2] + base[1] + base[0] + 1;
					base[2] = base[1] = base[0] = 0;
				}
			}
			
			if (sum > ans) ans = sum;
		}
		
	} while (next_permutation(order));
	
	cout << ans << '\n';
	
	return 0;
}
