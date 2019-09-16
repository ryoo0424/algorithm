#include <cstdio>
int main() {
	int t[15], p[15], d[16] = {0};
	int ans = 0, n;	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d %d", &t[i], &p[i]);
	for (int i=0; i<n; i++) {
		for (int j=i; j<n; j++) {
			if (j+t[i] <= n && d[j+t[i]] < d[i] + p[i])	d[j+t[i]] = d[i] + p[i];
		}
	}
	for (int i=0; i<=n; i++) if (d[i] > ans) ans = d[i];
	printf("%d\n", ans);
	return 0;
}
