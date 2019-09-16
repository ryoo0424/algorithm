#include <cstdio>
#include <malloc.h>

int main() {
	int n;	scanf("%d", &n);
	
	long long *room = (long long*)malloc(sizeof(long long)*n);
	
	for (int i=0; i<n; i++) scanf("%lld", &room[i]);
	
	int b, c;	scanf("%d %d", &b, &c);
	
	long long ans = 0;
	
	for (int i=0; i<n; i++) {
		ans += 1;
		
		if (room[i] - b > 0) {
			ans += (room[i] - b) / c;
			if ((room[i] - b) % c) ans += 1;
		}
	}
	
	printf("%lld\n", ans);
	
	free(room);
	
	return 0;
}
