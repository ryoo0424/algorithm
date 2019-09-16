#include <iostream>
#include <string>
#include <queue>
using namespace std;
int a[100][100]; 
int check[100][100];
int row[] = {1, 0, -1, 0};
int col[] = {0, -1, 0, 1};
#define P pair<int, int>
int main() {
	int n, m;	cin >> n >> m;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		for (int j=0; j<m; j++) a[i][j] = s[j] - '0';
	}
	queue<P> q;
	q.push(P(0, 0));
	check[0][0] = 1;
	while (!q.empty()) {
		P now = q.front();
		q.pop();
		for (int i=0; i<4; i++) {
			int r = now.first + row[i];
			int c = now.second + col[i];
			if (r >= 0 && r < n && c >= 0 && c < m) {
				if (!check[r][c] && a[r][c]) {
					check[r][c] = check[now.first][now.second] + 1;
					q.push(P(r, c));
				}
			}
		}
	}
	cout << check[n-1][m-1];
	return 0;
}
