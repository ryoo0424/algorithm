#include <cstdio>
#include <algorithm>

#define P pair<int, int>

using namespace std;

int n, m, d;
int castle[15][15];
int tmp[15][15];
int order[15];
int archer[3];

P find_target(int bowman) {
	for (int k=1; k<=d; k++) {
		for (int j=bowman-d+1; j<=bowman+d-1; j++) {
			for (int i=n-1; i>=n-d; i--) {
				if (0 <= i && i < n && 0 <= j && j < m && abs(n-i) + abs(bowman-j) == k) {
					if (tmp[i][j] == 1) {
						return P(i, j);
					}
				}
			}
		}
	}
	return P(-1, -1);
}

int attack() {
	int cnt = 0;
	
	P target[3];
	
	for (int k=0; k<3; k++) {
		target[k] = find_target(archer[k]);
	}
	
	for (int i=0; i<3; i++) {
		int r = target[i].first;
		int c = target[i].second;
		
		if (r != -1 && c != -1) {
			if (tmp[r][c] == 1) {
				cnt += 1;
				tmp[r][c] = 0;
			}
		}
	}
	
	return cnt;
}

void pulldown() {
	for (int i=n-1; i>0; i--) {
		for (int j=0; j<m; j++) {
			tmp[i][j] = tmp[i-1][j];
		}
	}
	for (int i=0; i<m; i++) tmp[0][i] = 0;
}

int main() {
	int ans = 0;
	scanf("%d %d %d", &n, &m, &d);
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			scanf("%d", &castle[i][j]);
		}
	}
	
	order[m-1] = order[m-2] = order[m-3] = 1;
	
	do {
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				tmp[i][j] = castle[i][j];
			}
		}
		
		int idx = 0, sum = 0;;
		
		for (int i=0; i<m; i++) {
			if (order[i] == 1) archer[idx++] = i;
		}
		
		for (int i=0; i<n; i++) {
			sum += attack();
			pulldown();
		}
		
		if (ans < sum) ans = sum;
	} while (next_permutation(order, order+m));
	
	printf("%d\n", ans);
	
	return 0;
}
