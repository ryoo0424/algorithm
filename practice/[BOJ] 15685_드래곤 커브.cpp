#include <iostream>
#include <vector>

using namespace std;

struct info {
	int r, c, d, g;
	info() {}
	info(int r, int c, int d, int g) : r(r), c(c), d(d), g(g) {}
};

int pow(int x, int e) {
	int ret = 1;
	for (int i=0; i<e; i++) ret *= x;
	return ret;
}

bool possible(bool map[101][101], int r, int c) {
	for (int i=r; i<=r+1; i++) {
		for (int j=c; j<=c+1; j++) {
			if (!map[i][j]) return false;
		}
	}
	return true;
}

int main() {
	vector<info> v;
	bool map[101][101] = {false};
	int dr[] = {0, -1, 0, 1};
	int dc[] = {1, 0, -1, 0};
	int n, ans = 0;	cin >> n;
	
	for (int i=0; i<n; i++) {
		int r, c, d, g;	cin >> c >> r >> d >> g;
		v.push_back(info(r, c, d, g));
	}
	
	for (int i=0; i<n; i++) {
		int dragon[1024] = { v[i].d }, gen = pow(2, v[i].g);
		for (int j=1; j<gen; j*=2) {
			for (int k=0; k<j; k++) {
				dragon[j+k] = (dragon[j-k-1] + 1) % 4;
			}
		}
		int r = v[i].r, c = v[i].c;
		for (int j=0; j<=gen; j++) {
			map[r][c] = true;
			r += dr[dragon[j]], c += dc[dragon[j]];
		}
	}
	
	for (int i=0; i<100; i++) {
		for (int j=0; j<100; j++) {
			if (possible(map, i, j)) ans += 1;
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
