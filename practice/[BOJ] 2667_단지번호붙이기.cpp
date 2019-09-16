/*
	해결 방법
	1. bfs가 실행된다 = 아직 방문한 적 없는 단지를 탐색한다
	2. 따라서 for 문을 돌면서 bfs가 호출될 때 마다 각 단지의 요소 수를 카운트 함
	3. bfs가 종료될 때까지 카운트 한 요소 수를 벡터에 추가
	4. 벡터를 정렬한 후 벡터 사이즈와 값 출력
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
