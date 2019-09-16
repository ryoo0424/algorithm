#include <iostream>

using namespace std;

int main() {
	int t;	cin >> t;
	int cafe[20][20];
	int dr[] = {-1, 1, 1, -1};
	int dc[] = {1, 1, -1, -1};
	
	for (int tc=1; tc<=t; tc++) {
		int n, ans = 0;	cin >> n;
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				cin >> cafe[i][j];
			}
		}
		
		for (int i=0; i<n-2; i++) {
			for (int j=1; j<n-1; j++) {
				for (int k=1; i+dr[1]*k < n-1 && j+dc[1]*k < n; k++) {
					for (int l=1; i+dr[1]*k+dr[2]*l < n && j+dc[1]*k+dc[2]*l > 0; l++) {
						int r = i, c = j;
						int check[101] = {0};
						// ¿ìÇÏ 
						for (int m=0; m<k; m++) {
							r += dr[1], c += dc[1];
							check[cafe[r][c]] += 1;
						}
						// ÁÂÇÏ 
						for (int m=0; m<l; m++) {
							r += dr[2], c += dc[2];
							check[cafe[r][c]] += 1;
						}
						
						if (r+dr[3]*k < 1 || c+dc[3]*k < 0) continue;
						// ÁÂ»ó 
						for (int m=0; m<k; m++) {
							r += dr[3], c += dc[3];
							check[cafe[r][c]] += 1;
						}
						//¿ì»ó 
						for (int m=0; m<l; m++) {
							r += dr[0], c += dc[0];
							check[cafe[r][c]] += 1;
						}
						
						int sum = 0;
						for (int kk=1; kk<=100; kk++) {
							if (check[kk] == 1) sum += 1;
							else if (check[kk] >= 2) sum = -987654321;
						}
						
						if (sum > ans) ans = sum;
					}
				}
			}
		}
		
		if (ans == 0) ans = -1;
		
		cout << "#" << tc << " " << ans << '\n';
	}
	return 0;
}
