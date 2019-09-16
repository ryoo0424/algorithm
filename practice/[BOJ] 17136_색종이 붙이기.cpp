#include <iostream>
#include <vector>

#define P pair<int, int>

using namespace std;

int paper[10][10];
int type[6];
int ans = 987654321;
vector<P> v;

bool possible(int r, int c, int k) {
	if (r + k > 10 || c + k > 10) return false;
	
	for (int i=r; i<r+k; i++) {
		for (int j=c; j<c+k; j++) {
			if (paper[i][j] == 0) return false;
		}
	}
	
	return true;
}

void set(int r, int c, int k, int v) {
	for (int i=r; i<r+k; i++) {
		for (int j=c; j<c+k; j++) {
			paper[i][j] = v;
		}
	}
}

void dfs(int idx, int use, int cnt) {
	if (cnt == v.size()) {
		ans = (ans > use ? use : ans);
		return;
	}
	
	if (use > ans || idx > v.size()) return;
	
	int r = v[idx].first;
	int c = v[idx].second;
	
	if (paper[r][c] == 0) {
		dfs(idx+1, use, cnt);
		return;
	}
	
	for (int k=5; k>=1; k--) {	
		if (possible(r, c, k) && type[k] < 5) {
			type[k] += 1;
			set(r, c, k, 0);
			dfs(idx+1, use+1, cnt+k*k);
			set(r, c, k, 1);
			type[k] -= 1;
		}
	}
}

int main() {
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			cin >> paper[i][j];
			if (paper[i][j] == 1) v.push_back(P(i, j));
		}
	}

	dfs(0, 0, 0);
	
	cout << (ans == 987654321 ? -1 : ans) << '\n';
	
	return 0;
}
