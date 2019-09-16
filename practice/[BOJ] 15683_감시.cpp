#include <iostream>
using namespace std;

struct P { 
	int first, second; 
	P(){}
	P(int a, int b) : first(a), second(b) {}
};

int row[] = {0, 1, 0, -1};
int col[] = {1, 0, -1, 0};
int r, c, cnt, ans, order[8], map[8][8];
P CCTV[8];

void calc() {
	bool tmp[8][8] = {false};
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (map[i][j] != 0) tmp[i][j] = true;
		}
	}

	for (int i=0; i<cnt; i++) {
		int tr = CCTV[i].first;
		int tc = CCTV[i].second;
		int td = order[i];
		int tv = map[tr][tc];
		
		int nr = tr + row[td];
		int nc = tc + col[td];
		while (0 <= nr && nr < r && 0 <= nc && nc < c && map[nr][nc] != 6) {
			tmp[nr][nc] = true;
			nr += row[td];
			nc += col[td];
		}
		
		if (tv == 2) {
			td = (td + 2) % 4;
			nr = tr + row[td];
			nc = tc + col[td];
			while (0 <= nr && nr < r && 0 <= nc && nc < c && map[nr][nc] != 6) {
				tmp[nr][nc] = true;
				nr += row[td];
				nc += col[td];
			}
		} else if (tv >= 3) {
			for (int j=0; j<tv-2; j++) {
				td = (td + 3) % 4;
				nr = tr + row[td];
				nc = tc + col[td];
				while (0 <= nr && nr < r && 0 <= nc && nc < c && map[nr][nc] != 6) {
					tmp[nr][nc] = true;
					nr += row[td];
					nc += col[td];
				}
			}
		}
	}
//	
//	cout << '\n';
//	for (int i=0; i<r; i++) {
//		for (int j=0; j<c; j++) {
//			cout << tmp[i][j] << " ";
//		}
//		cout << '\n';
//	}
//	

	int sum = r * c;
	
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (tmp[i][j]) sum -= 1;
		}
	}
	
	if (sum < ans) ans = sum;
}

void dfs(int depth) {
	if (depth == cnt) return;
	
	for (int i=0; i<4; i++) {
		order[depth] = i;
		calc();
		dfs(depth+1);
	}
}

int main() {
	cin >> r >> c;
	
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			cin >> map[i][j];
			if (1 <= map[i][j] && map[i][j] <= 5) CCTV[cnt++] = P(i, j);
			if (map[i][j] == 6) ans -= 1;
		}
	}
	
	ans += r * c;
	
	dfs(0);
	
	cout << ans << '\n';
	
	return 0;
}
