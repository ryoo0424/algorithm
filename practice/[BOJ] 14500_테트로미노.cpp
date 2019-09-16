#include <iostream>
using namespace std;
int paper[500][500];
int n, m;	
int calc(int r, int c) {
	int sum = 0, tmp = 0;
	// ¤Ñ 
	if (c+3 < m) {
		tmp = 0;
		for (int i=0; i<4; i++) tmp += paper[r][c+i];
		if (tmp > sum) sum = tmp;
	}
	if (r+3 < n) {
		tmp = 0;
		for (int i=0; i<4; i++) tmp += paper[r+i][c];
		if (tmp > sum) sum = tmp;
	}
	if (c-3 >= 0) {
		tmp = 0;
		for (int i=0; i<4; i++) tmp += paper[r][c-i];
		if (tmp > sum) sum = tmp;
	}
	if (r-3 >= 0) {
		tmp = 0;
		for (int i=0; i<4; i++) tmp += paper[r-i][c];
		if (tmp > sum) sum = tmp;
	}
	// ¤±
	if (r+1 < n && c+1 < m) {
		tmp = 0;
		for (int i=0; i<2; i++) {
			for (int j=0; j<2; j++) {
				tmp += paper[r+i][c+j];
			}
		}
		if (tmp > sum) sum = tmp;
	}
	if (r+1 < n && c-1 >= 0) {
		tmp = 0;
		for (int i=0; i<2; i++) {
			for (int j=0; j<2; j++) {
				tmp += paper[r+i][c-j];
			}
		}
		if (tmp > sum) sum = tmp;
	}
	if (r-1 >= 0 && c-1 >= 0) {
		tmp = 0;
		for (int i=0; i<2; i++) {
			for (int j=0; j<2; j++) {
				tmp += paper[r-i][c-j];
			}
		}
		if (tmp > sum) sum = tmp;
	}
	if (r-1 >= 0 && c+1 < m) {
		tmp = 0;
		for (int i=0; i<2; i++) {
			for (int j=0; j<2; j++) {
				tmp += paper[r-i][c+j];
			}
		}
		if (tmp > sum) sum = tmp;
	}
	// ¤¤
	if (r+2 < n && c+1 < m) {
		tmp = 0;
		for (int i=0; i<3; i++) tmp += paper[r+i][c];
		tmp += paper[r+2][c+1];
		if (tmp > sum) sum = tmp;
	}
	if (r-1 >= 0 && c+2 < m) {
		tmp = 0;
		for (int i=0; i<3; i++) tmp += paper[r][c+i];
		tmp += paper[r-1][c+2];
		if (tmp > sum) sum = tmp;
	}
	if (r-2 >= 0 && c-1 >= 0) {
		tmp = 0;
		for (int i=0; i<3; i++) tmp += paper[r-i][c];
		tmp += paper[r-2][c-1];
		if (tmp > sum) sum = tmp;
	}
	if (r+1 < n && c-2 >= 0) {
		tmp = 0;
		for (int i=0; i<3; i++) tmp += paper[r][c-i];
		tmp += paper[r+1][c-2];
		if (tmp > sum) sum = tmp;
	}
	// ¤¤2
	if (r+2 < n && c-1 >= 0) {
		tmp = 0;
		for (int i=0; i<3; i++) tmp += paper[r+i][c];
		tmp += paper[r+2][c-1];
		if (tmp > sum) sum = tmp;
	}
	if (r+1 < n && c+2 < m) {
		tmp = 0;
		for (int i=0; i<3; i++) tmp += paper[r][c+i];
		tmp += paper[r+1][c+2];
		if (tmp > sum) sum = tmp;
	}
	if (r-2 >= 0 && c+1 < m) {
		tmp = 0;
		for (int i=0; i<3; i++) tmp += paper[r-i][c];
		tmp += paper[r-2][c+1];
		if (tmp > sum) sum = tmp;
	}
	if (r-1 >= 0 && c-2 >= 0) {
		tmp = 0;
		for (int i=0; i<3; i++) tmp += paper[r][c-i];
		tmp += paper[r-1][c-2];
		if (tmp > sum) sum = tmp;
	}
	// ¤Ç
	if (r+1 < n && c+2 < m) {
		tmp = 0;
		for (int i=0; i<3; i++) tmp += paper[r][c+i];
		tmp += paper[r+1][c+1];
		if (tmp > sum) sum = tmp;
	}
	if (r-2 >= 0 && c+1 < m) {
		tmp = 0;
		for (int i=0; i<3; i++) tmp += paper[r-i][c];
		tmp += paper[r-1][c+1];
		if (tmp > sum) sum = tmp;
	}
	if (r-1 >= 0 && c-2 >= 0) {
		tmp = 0;
		for (int i=0; i<3; i++) tmp += paper[r][c-i];
		tmp += paper[r-1][c-1];
		if (tmp > sum) sum = tmp;
	}
	if (r+2 < n && c-1 >= 0) {
		tmp = 0;
		for (int i=0; i<3; i++) tmp += paper[r+i][c];
		tmp += paper[r+1][c-1];
		if (tmp > sum) sum = tmp;
	}
	// ¤Ç2
	if (r-1 >= 0 && c+2 < m) {
		tmp = 0;
		for (int i=0; i<3; i++) tmp += paper[r][c+i];
		tmp += paper[r-1][c+1];
		if (tmp > sum) sum = tmp;
	}
	if (r-2 >= 0 && c-1 >= 0) {
		tmp = 0;
		for (int i=0; i<3; i++) tmp += paper[r-i][c];
		tmp += paper[r-1][c-1];
		if (tmp > sum) sum = tmp;
	}
	if (r+1 < n && c-2 >= 0) {
		tmp = 0;
		for (int i=0; i<3; i++) tmp += paper[r][c-i];
		tmp += paper[r+1][c-1];
		if (tmp > sum) sum = tmp;
	}
	if (r+2 < n && c+1 < m) {
		tmp = 0;
		for (int i=0; i<3; i++) tmp += paper[r+i][c];
		tmp += paper[r+1][c+1];
		if (tmp > sum) sum = tmp;
	}
	// ¤©
	if (r+2 < n && c+1 < m) {
		tmp = 0;
		tmp += paper[r][c] + paper[r+1][c] + paper[r+1][c+1] + paper[r+2][c+1];
		if (tmp > sum) sum = tmp;
	}
	if (r-1 >= 0 && c+2 < m) {
		tmp = 0;
		tmp += paper[r][c] + paper[r][c+1] + paper[r-1][c+1] + paper[r-1][c+2];
		if (tmp > sum) sum = tmp;
	}
	if (r-2 >= 0 && c-1 >= 0) {
		tmp = 0;
		tmp += paper[r][c] + paper[r-1][c] + paper[r-1][c-1] + paper[r-2][c-1];
		if (tmp > sum) sum = tmp;
	}if (r+1 < n && c-2 >= 0) {
		tmp = 0;
		tmp += paper[r][c] + paper[r][c-1] + paper[r+1][c-1] + paper[r+1][c-2];
		if (tmp > sum) sum = tmp;
	}
	// ¤©2
	if (r+2 < n && c-1 >= 0) {
		tmp = 0;
		tmp += paper[r][c] + paper[r+1][c] + paper[r+1][c-1] + paper[r+2][c-1];
		if (tmp > sum) sum = tmp;
	}
	if (r+1 < n && c+2 < m) {
		tmp = 0;
		tmp += paper[r][c] + paper[r][c+1] + paper[r+1][c+1] + paper[r+1][c+2];
		if (tmp > sum) sum = tmp;
	}
	if (r-2 >= 0 && c+1 < m) {
		tmp = 0;
		tmp += paper[r][c] + paper[r-1][c] + paper[r-1][c+1] + paper[r-2][c+1];
		if (tmp > sum) sum = tmp;
	}if (r-1 >= 0 && c-2 >= 0) {
		tmp = 0;
		tmp += paper[r][c] + paper[r][c-1] + paper[r-1][c-1] + paper[r-1][c-2];
		if (tmp > sum) sum = tmp;
	}
	return sum;
}
int main() {cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> paper[i][j];
		}
	}
	int ans = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			int result = calc(i, j);
			if (result > ans) ans = result;
		}
	}
	cout << ans << '\n';
	return 0;
}
