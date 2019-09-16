/*
	접근 방법
	1. 현재 격자판의 상태에서 목표 격자칸과 다른 칸을 찾는다.
	2. 1.에서 찾은 칸의 상하좌우를 살펴 회전이 가능한 가로 혹은 세로 방향을 찾는다.
	3. 백트래킹을 통해 1-2를 반복한다. 
*/
#include <iostream>
#include <vector>

using namespace std;

struct method {
	int r, c, k;
	method() {}
	method(int r, int c, int k) : r(r), c(c), k(k) {}
};

vector<method> v; 
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int rect[4][4];
int tmp[4];

void move_row(int r, int k) {
	for (int i=0; i<4; i++) tmp[i] = rect[r][i];
	for (int i=0; i<4; i++) rect[r][i] = tmp[(i+(4-k))%4];
}

void move_col(int c, int k) {
	for (int i=0; i<4; i++) tmp[i] = rect[i][c];
	for (int i=0; i<4; i++) rect[i][c] = tmp[(i+(4-k))%4];
}

bool correct(int i, int j) {
	return rect[i][j] == i * 4 + j + 1;
}

int direction(int i, int j) {
	for (int k=0; k<4; k++) {
		int r = i + dr[k];
		int c = j + dc[k];
		if (0 <= r && r < 4 && 0 <= c && c < 4 && !correct(r, c)) return k % 2;
	}
}

void show() {
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			cout << rect[i][j] << " ";
		}
		cout << '\n';
	}
}

int main() {
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			cin >> rect[i][j];
		}
	}
	
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			if (!correct(i, j)) {
				int cnt = 0, target = i * 4 + j + 1;
				if (direction(i, j)) {	// row
					int k = j;
					while (rect[i][k] != target) {
						k = (k + 1) % 4;
						cnt += 1;
					}
					move_row(i, 4-cnt);
					v.push_back(method(1, i+1, 4-cnt));
				} else {				// col
					int k = i;
					while (rect[k][j] != target) {
						k = (k + 1) % 4;
						cnt += 1;
					}
					move_col(j, 4-cnt);
					v.push_back(method(2, j+1, 4-cnt));
				}
			}
		}
	}
	
	cout << v.size() << '\n';
	for (int i=0; i<v.size(); i++) cout << v[i].r << " " << v[i].c << " " << v[i].k << '\n';
	
	return 0;
}
