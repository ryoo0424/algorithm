#include<cstdio>
#include<queue>
using namespace std;
int main(void){
	queue<int> q;
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; i++) q.push(i);
	printf("<");
	while (!q.empty()) {
		for (int j=0; j<m-1; j++) {
			q.push(q.front());
			q.pop();
		}
		if (q.size() == 1) printf("%d>\n", q.front());
		else printf("%d, ", q.front());
		q.pop();
	}
	return 0;
}
