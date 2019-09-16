#include <iostream>
using namespace std;
int dice[6];
void move_right() {
	int x = dice[5];
	dice[5] = dice[3];
	dice[3] = dice[2];
	dice[2] = dice[1];
	dice[1] = x;
}
void move_left() {
	int x = dice[1];
	dice[1] = dice[2];
	dice[2] = dice[3];
	dice[3] = dice[5];
	dice[5] = x;
}
void move_up() {
	int x = dice[0];
	dice[0] = dice[2];
	dice[2] = dice[4];
	dice[4] = dice[5];
	dice[5] = x;
}
void move_down() {
	int x = dice[5];
	dice[5] = dice[4];
	dice[4] = dice[2];
	dice[2] = dice[0];
	dice[0] = x;
}
int main() {
	int map[20][20] = {0};
	int dx[] = {0, 0, 0, -1, 1};
	int dy[] = {0, 1, -1, 0, 0}; 
	int n, m, x, y, k;	cin >> n >> m >> x >> y >> k;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i=0; i<k; i++) {
		int d;	cin >> d;
		cout << "BEFORE > ";
		for (int i=0; i<6; i++) cout << dice[i] << " ";	cout << '\n';
		if (x + dx[d] < 0 || x + dx[d] >= n || y + dy[d] < 0 || y + dy[d] >= m) continue;
		x += dx[d];
		y += dy[d];
		if (d == 1) move_right();
		else if (d == 2) move_left();
		else if (d == 3) move_up();
		else move_down();
		if (map[x][y] == 0) map[x][y] = dice[5];
		else {
			dice[5] = map[x][y];
			map[x][y] = 0;
		}
		cout << " AFTER > ";
		for (int i=0; i<6; i++) cout << dice[i] << " ";	cout << '\n';
		cout << dice[2] << '\n';
	}
	return 0;
}
