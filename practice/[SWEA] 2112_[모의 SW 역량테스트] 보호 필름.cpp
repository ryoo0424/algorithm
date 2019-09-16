#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void copy(int tmp[13][20], int film[13][20], int d, int w) {
	for (int i=0; i<d; i++) {
		for (int j=0; j<w; j++) {
			tmp[i][j] = film[i][j];
		}
	}
}

bool pass(int tmp[13][20], int col, int d, int w, int k) {
	int cnt = 1;
	for (int i=1; i<d; i++) {
		if (tmp[i][col] == tmp[i-1][col]) cnt += 1;
		else cnt = 1;
		if (cnt >= k) return true;
	}
	return false;
}

int main() {
	int film[13][20];
	int tmp[13][20];
	int t;	cin >> t;
	
	for (int tc=1; tc<=t; tc++) {
		int d, w, s, ans = 987654321;	cin >> d >> w >> s;
		
		for (int i=0; i<d; i++) {
			for (int j=0; j<w; j++) {
				cin >> film[i][j];
			}
		}
		
		for (int i=d-1; i>=0; i--) {
			vector<int> v;
			for (int j=0; j<i; j++) v.push_back(0);
			for (int j=i+1; j<=d; j++) v.push_back(1);
			
			do {
				int sumA = 0, sumB = 0;
				bool f = true, flagA = false, flagB = false;
				copy(tmp, film, d, w);
				for (int k=0; k<w; k++) if (!pass(tmp, k, d, w, s)) f = false;
				// A (=0)
				for (int j=0; j<=d; j++) {
					if (v[j] == 1) {
						sumA += 1;
						for (int k=0; k<w; k++) tmp[j][k] = 0;
						bool flag = true;
						for (int k=0; k<w; k++) if (!pass(tmp, k, d, w, s)) flag = false;
						if (flag) {
							flagA = true;
							break;
						}
					}
				}
				// B (=1)
				copy(tmp, film, d, w);
				for (int j=0; j<=d; j++) {
					if (v[j] == 1) {
						sumB += 1;
						for (int k=0; k<w; k++) tmp[j][k] = 1;
						bool flag = true;
						for (int k=0; k<w; k++) if (!pass(tmp, k, d, w, s)) flag = false;
						if (flag) {
							flagB = true;
							break;
						}
					}
				}
				
				if (flagA || flagB) ans = (f ? 0 : min(ans, min(sumA, sumB)));
			} while (next_permutation(v.begin(), v.end()));
		}
		
		cout << "#" << tc << " " << ans << '\n';
		
	}
	return 0;
}
