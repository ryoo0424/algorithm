#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie();
	int table[100][100];
	
	for (int t=1; t<=10; t++) {
		int n, ans = 0;	cin >> n;
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				cin >> table[i][j];
			}
		}
		
		for (int j=0; j<n; j++) {
			queue<int> q;
			for (int i=0; i<n; i++) if (table[i][j] == 1) q.push(i);
			
			while (!q.empty()) {
				int st = q.front();
				q.pop();
				while (!q.empty() && st == q.front()) {
					st = q.front();
					q.pop();
				}
				int ed = (!q.empty() ? q.front() : n);
				bool flag = false;
				for (int i=st; i<ed; i++) if (table[i][j] == 2) flag = true;
				if (flag) ans +=1;
			}
		}
		
		cout << "#" << t << " " << ans << '\n';
	}
	
	return 0;
}
