#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct coord {
	int x, y, z;
	coord(int x, int y, int z) : x(x), y(y), z(z) {}
} coord;

int row[] = {0, 0, -1, 1};
int col[] = {1, -1, 0, 0};
int maze[5][5][5];
int check[5][5][5];
int tmp[5][5][5];
int ans = 987654321;

void show() {
	for (int i=0; i<5; i++) {
		for (int j=0; j<5; j++) {
			for (int k=0; k<5; k++) {
				printf("%d ", tmp[i][j][k]);
			}
			puts("");
		}
		puts("");
	}
	puts("");
}

bool ok(int x, int y) {
	if (0 <= x && x < 5 && 0 <= y && y < 5) return true;
	return false;
}

void rotate(int maze[5][5]) {
	int tmp[5][5];
	for (int i=0; i<5; i++) for (int j=0; j<5; j++) tmp[4-j][i] = maze[i][j];
	for (int i=0; i<5; i++) for (int j=0; j<5; j++) maze[i][j] = tmp[i][j];
}

void bfs() {
	memset(check, 0, sizeof(check));
	check[0][0][0] = 1;
	queue<coord> q;
	q.push(coord(0, 0, 0));
	
	while (!q.empty()) {
		coord now = q.front();
		bool flag = false;
		if (check[now.x][now.y][now.z] >= 5) flag = true;
		if (flag) show();
		if (flag) printf("########################\ncurr : (%d, %d, %d) = %d\n", now.x, now.y, now.z, check[now.x][now.y][now.z]);
		if (now.x == 4 && now.y == 4 && now.z == 4) {
			puts("---goal!---");
			show();
			if (check[4][4][4] - 1 < ans) ans = check[4][4][4] - 1;
			return;
		}
		
		q.pop();
		
		if (now.x == 0 || now.x == 4) {			// À­¸é, ¾Æ·§¸é 
			for (int i=0; i<4; i++) {
				int nx = now.x;
				int ny = now.y + row[i];
				int nz = now.z + col[i];
				if (ok(ny, nz)) {
					if (check[nx][ny][nz] == 0 && tmp[nx][ny][nz] == 1) {
						if (flag) printf("[X] next : (%d, %d, %d) = %d\n", nx, ny, nz, check[nx][ny][nz]);
						check[nx][ny][nz] = check[now.x][now.y][now.z] + 1;
						q.push(coord(nx, ny, nz));
					}
				}
			}
		}
	
		if (now.y == 0 || now.y == 4) {			// ¾Õ¸é, µÞ¸é 
			for (int i=0; i<4; i++) {
				int nx = now.x + row[i];
				int ny = now.y;
				int nz = now.z + col[i];
				if (ok(nx, nz)) {
					if (check[nx][ny][nz] == 0 && tmp[nx][ny][nz] == 1) {
						if (flag) printf("[Y] next : (%d, %d, %d) = %d\n", nx, ny, nz, check[nx][ny][nz]);
						check[nx][ny][nz] = check[now.x][now.y][now.z] + 1;
						q.push(coord(nx, ny, nz));
					}
				}
			}
		}
		
		if (now.z == 0 || now.z == 4) {			// ¿À¸¥ÂÊ ¸é, ¿ÞÂÊ ¸é 
			for (int i=0; i<4; i++) {
				int nx = now.x + row[i];
				int ny = now.y + col[i];
				int nz = now.z;
				if (ok(nx, ny)) {
					if (check[nx][ny][nz] == 0 && tmp[nx][ny][nz] == 1) {
						if (flag) printf("[Z] next : (%d, %d, %d) = %d\n", nx, ny, nz, check[nx][ny][nz]);
						check[nx][ny][nz] = check[now.x][now.y][now.z] + 1;
						q.push(coord(nx, ny, nz));
					}
				}
			}
		}
	}
}

int main() {
	for (int i=0; i<5; i++) {
		for (int j=0; j<5; j++) {
			for (int k=0; k<5; k++) {
				scanf("%d", &maze[i][j][k]);
			}
		}
	}

	for (int a=0; a<4; a++) {
		for (int b=0; b<4; b++) {
			for (int c=0; c<4; c++) {
				for (int d=0; d<4; d++) {
					for (int e=0; e<4; e++) {
						int order[5] = {0, 1, 2, 3, 4};
						do {
							for (int i=0; i<5; i++) {
								for (int j=0; j<5; j++) {
									for (int k=0; k<5; k++) {
										tmp[i][j][k] = maze[order[i]][j][k];
									}
								}
							}
							if (tmp[0][0][0] && tmp[4][4][4]) { bfs(); }
						} while (next_permutation(order, order+5));
						rotate(maze[4]);
					}
					rotate(maze[3]);
				}
				rotate(maze[2]);
			}
			rotate(maze[1]);
		}
		rotate(maze[0]);
	}
	
	printf("%d\n", (ans == 987654321 ? -1 : ans));
	return 0;
}
