#include <cstdio>
#include <algorithm>
using namespace std;
int a[20][20];
bool check[20];
int n, ans = 987654321;
void go(int now, int cnt) {
	if (cnt == n/2) {
		int team1[20], team2[20];
		for (int i=0, j=0, k=0; i<n; i++) {
			if (check[i]) team1[j++] = i;
			else team2[k++] = i;
		}
//		printf("TEAM1 : ");
//		for (int i=0; i<n/2; i++) printf("%2d ", team1[i]); puts("");
//		printf("TEAM2 : ");
//		for (int i=0; i<n/2; i++) printf("%2d ", team2[i]); puts("\n");
		
		int diff = 0;
		
		for (int i=0; i<n/2; i++) {
			for (int j=i+1; j<n/2; j++) {
				diff += a[team1[i]][team1[j]] + a[team1[j]][team1[i]];
				diff -= a[team2[i]][team2[j]] + a[team2[j]][team2[i]];
			}
		}
		
		ans = min(ans, abs(diff));
		return;
	}
	
	for (int i=now+1; i<n; i++) {
		if (!check[i]) {
			check[i] = true;
			go(i, cnt + 1);
			check[i] = false;
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) scanf("%d", &a[i][j]);
	go(0, 0);
	printf("%d\n", ans);
	return 0;
}
