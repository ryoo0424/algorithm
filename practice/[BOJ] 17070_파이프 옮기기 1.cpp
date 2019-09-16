#include <iostream>

using namespace std;

int n;
int room[17][17];
int d[17][17][3];
int row[] = {-1, -1, 0};
int col[] = {-1, 0, -1};

int main() {
	cin >> n;
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cin >> room[i][j];
		}
	}
	
	d[1][2][0] = 1;
	
	for (int i=1; i<=n; i++) {
		for (int j=2; j<=n; j++) {
			if (room[i][j] != 1) {
				d[i][j][0] += d[i][j-1][0] + d[i][j-1][2];
				d[i][j][1] += d[i-1][j][1] + d[i-1][j][2];
				if (room[i-1][j] != 1 && room[i][j-1] != 1) d[i][j][2] += d[i-1][j-1][0] + d[i-1][j-1][1] + d[i-1][j-1][2];
			}
		}
	}
	
	cout << d[n][n][0] + d[n][n][1] + d[n][n][2] << '\n';
	
	return 0;
}
