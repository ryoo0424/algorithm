#include <iostream>
#include <cstring>

using namespace std;

typedef struct micro {
	int size, dir;
	micro() {}
	micro(int size, int dir) : size(size), dir(dir) {}
} micro;

int t, n, m, k;
micro area[100][100];
micro tmp[100][100];
int row[] = {0, -1, 1, 0, 0};
int col[] = {0, 0, 0, -1, 1};

void move() {
	memset(tmp, 0, sizeof(tmp));
	
	for (int o=0; o<n; o++) {
		for (int p=0; p<n; p++) {
			if (area[o][p].size <= 0) continue;
			
			int i = o + row[area[o][p].dir];
			int j = p + col[area[o][p].dir]; 
			
			int dir, max_size = 0;
			bool flag = false;
			
			for (int h=1; h<=4; h++) {
				int r = i + row[h];
				int c = j + col[h];
				
				if (0 <= r && r < n && 0 <= c && c < n) {
					if (area[r][c].size > 0) {
						int s = area[r][c].size;
						int d = area[r][c].dir;
						
						if ((h==1 && d==2) || (h==2 && d==1) || (h==3 && d==4) || (h==4 && d==3)) {
							if (s > max_size) {
								dir = d;
								max_size = s;
							}
							
							tmp[i][j].size += area[r][c].size;
							tmp[i][j].dir = dir;
							area[r][c].size = 0;
							area[r][c].dir = 0;
							flag = true;
						}
					}
				}
			}
			
			if (!flag) continue;
			
			if (i == 0 || i == n-1) {
				tmp[i][j].size /= 2;
				if (tmp[i][j].size == 0) tmp[i][j].dir = 0;
				else tmp[i][j].dir = 3 - tmp[i][j].dir;
			}
			
			if (j == 0 || j == n-1) {
				tmp[i][j].size /= 2;
				if (tmp[i][j].size == 0) tmp[i][j].dir = 0;
				else tmp[i][j].dir = 7 - tmp[i][j].dir;
			}
		}
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			area[i][j] = tmp[i][j];
		}
	}
}

int main() {
	cin >> t;
	
	for (int x=1; x<=t; x++) {
		memset(area, 0, sizeof(area));
		int ans = 0;
		
		cin >> n >> m >> k;
		
		for (int i=0; i<k; i++) {
			int r, c, size, dir;	cin >> r >> c >> size >> dir;
			area[r][c] = micro(size, dir);
		}
		
		while (m--) move();
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				ans += area[i][j].size;
			}
		}
		
		cout << "#" << x << " " << ans << '\n';
	}
	
	return 0;
}
