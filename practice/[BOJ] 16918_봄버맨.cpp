#include <iostream>
using namespace std;
int r, c, n;
int a[200][200];
bool check[200][200];
int row[] = {0, 0, 1, 0, -1};
int col[] = {0, 1, 0, -1, 0};
void bomb() {
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (check[i][j]) {			
				for (int k=0; k<5; k++) {
					int nr = i + row[k];
					int nc = j + col[k];
					if (0 <= nr && nr < r && 0 <= nc && nc < c) a[nr][nc] = 0;
				}
			}
		}
	}
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			check[i][j] = false;
		}
	}
}
void fill() {
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (a[i][j] == 0) a[i][j] = 3;
		}
	}
}
void show() {
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (a[i][j] > 0) cout << 'O';
			else cout << '.';
		}
		cout << '\n';
	}
}
void countdown() {
	bool flag = false;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (a[i][j] > 1) a[i][j] -= 1;
			else if (a[i][j] == 1){ 
				check[i][j] = true;
				flag = true;
			}
		}
	}
	if (flag) bomb();
}
int main() {
	cin >> r >> c >> n;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			char c;	cin >> c;
			if (c == 'O') a[i][j] = 3;
			else a[i][j] = 0;
		}
	}
	int cnt = 0;
	while (cnt++ < n) {
		countdown();
		if (cnt != 0 && cnt % 2 == 0) fill();
	}
	show();
	return 0;
}
