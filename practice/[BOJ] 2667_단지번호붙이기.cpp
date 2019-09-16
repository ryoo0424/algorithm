/*
	�ذ� ���
	1. bfs�� ����ȴ� = ���� �湮�� �� ���� ������ Ž���Ѵ�
	2. ���� for ���� ���鼭 bfs�� ȣ��� �� ���� �� ������ ��� ���� ī��Ʈ ��
	3. bfs�� ����� ������ ī��Ʈ �� ��� ���� ���Ϳ� �߰�
	4. ���͸� ������ �� ���� ������� �� ���
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define P pair<int, int>

using namespace std; 

int row[] = {0, 1, 0, -1};
int col[] = {-1, 0, 1, 0};
int map[25][25];
bool check[25][25];
vector<int> v;
int n;

void bfs(int r, int c) {
	queue<P> q;
	q.push(P(r, c));
	check[r][c] = true;
	int cnt = 1;
	while (!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();
		for (int i=0; i<4; i++) {
			int nr = cr + row[i];
			int nc = cc + col[i];
			if (0 <= nr && nr < n && 0 <= nc && nc < n) {
				if (!check[nr][nc] && map[nr][nc] == 1) {
					q.push(P(nr, nc));
					check[nr][nc] = true;
					cnt += 1;
				}
			}
		}
	}
	v.push_back(cnt);
}

int main() {
	scanf("%d", &n);
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}	
		
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (!check[i][j] && map[i][j] == 1) bfs(i, j);
		}
	}
		
	sort(v.begin(), v.end());
	
	printf("%d\n", v.size());
	for (int i=0; i<v.size(); i++) printf("%d\n", v[i]);
	
	return 0;
}
