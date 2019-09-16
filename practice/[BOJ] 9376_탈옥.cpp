#include <iostream>
#include <queue>
#define P pair<int, int>
using namespace std;
int a[100][100], b[100][100];
bool ca[100][100], cb[100][100];
int row[] = {0, 1, 0, -1};
int col[] = {1, 0, -1, 0};
int h, w;
queue<P> prisoner;
void go() {
	queue<P> q1;
	q1.push(prisoner.front());	prisoner.pop();
	queue<P> q2;
	q2.push(prisoner.front());	prisoner.pop();
	while (true) {
		int size = q1.size();
		for (int i=0; i<size; i++) {				
			int cR = q1.front().first;
			int cC = q1.front().second;
			
			q1.pop();
			for (int i=0; i<4; i++) {
				int nR = cR + row[i];
				int nC = cC + col[i];
				if (0 <= nR && nR < h && 0 <= nC && nC < w) {
					if (!ca[nR][nC]) {
						if (a[nR][nC] == 0) { a[nR][nC] = a[cR][cC]; }
						else if (a[nR][nC] == -1) { a[nR][nC] = a[cR][cC] + 1; }
						ca[nR][nC] = true;
						q1.push(P(nR, nC));
					}
				}
			}
		}
		size = q2.size();
		
	}
}
int main() {
	int t;	cin >> t;
	while (t--) {
		cin >> h >> w;
		for (int i=0; i<h; i++) {
			for (int j=0; j<w; j++) {
				char c;	cin >> c;
				if (c == '*') { a[i][j] = b[i][j] = -2; }		// º® 
				else if (c == '#') { a[i][j] = b[i][j] = -1; } 	// ¹® 
				else if (c == '.') { a[i][j] = b[i][j] = 0; } 	// ±æ 
				else { 											// ÁË¼ö
					a[i][j] = b[i][j] = 0;
					prisoner.push(P(i, j));
					ca[i][j] = cb[i][j] = true;
				}
			}
		}
		go();
	}
	return 0;
}
