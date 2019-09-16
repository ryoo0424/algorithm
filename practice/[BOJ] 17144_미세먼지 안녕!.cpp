#include <iostream>
#include <cstring>

using namespace std;

int room[50][50];
int tmp[50][50];
int row[] = {0, 0, -1, 1};
int col[] = {-1, 1, 0, 0};
int r, c, t, x, y;

void diffusion() {
	memset(tmp, 0, sizeof(tmp));
	
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (room[i][j] > 0) {
				tmp[i][j] += room[i][j];
				int dust = room[i][j] / 5;
				
				for (int k=0; k<4; k++) {
					int nr = i + row[k];
					int nc = j + col[k];
					
					if (0 <= nr && nr < r && 0 <= nc && nc < c) {
						if (room[nr][nc] != -1) {
							tmp[nr][nc] += dust;
							tmp[i][j] -= dust;
						}
					}
				}
			}
		}
	}
	
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (tmp[i][j] > 0) room[i][j] = tmp[i][j];
		}
	}
}

void cleaner() {
	// upper side
	for (int i=x-2; i>0; i--) room[i][0] = room[i-1][0];
	for (int i=0; i<c-1; i++) room[0][i] = room[0][i+1];
	for (int i=0; i<x-1; i++) room[i][c-1] = room[i+1][c-1];
	for (int i=c-1; i>1; i--) room[x-1][i] = room[x-1][i-1];
	room[x-1][1] = 0;
	// lower side
	for (int i=x+1; i<r-1; i++) room[i][0] = room[i+1][0];
	for (int i=0; i<c-1; i++) room[r-1][i] = room[r-1][i+1];
	for (int i=r-1; i>x; i--) room[i][c-1] = room[i-1][c-1];
	for (int i=c-1; i>1; i--) room[x][i] = room[x][i-1];
	room[x][1] = 0;
}

int fine_dust() {
	int ret = 0;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (room[i][j] > 0) ret += room[i][j];
		}
	}
	return ret;
}

int main() {
	cin >> r >> c >> t;
	
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			cin >> room[i][j];
			if (room[i][j] == -1) x = i, y = j;		// 공기청정기 아래 좌표 입력 
		}
	}
	
	while (t-- > 0) {
		diffusion();
		cleaner();
	}
	
	cout << fine_dust() << '\n';
	
	return 0;
}
