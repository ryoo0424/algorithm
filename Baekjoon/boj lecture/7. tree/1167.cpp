#include<cstdio>
#include<vector>
using namespace std;
const int MAX = 100001;
vector< pair<int,int> > t[MAX];
bool check1[MAX];
bool check2[MAX];
int main() {
	int n;
	scanf("%d", &n);
	while (n--) { // init
		int u, v, dist;
		scanf("%d", &u);
		scanf("%d", &v);
		while (v != -1) {
			scanf("%d", &dist);
			t[u].push_back(make_pair(v, dist));
			t[v].push_back(make_pair(u, dist));
			scanf("%d", &v);
		}
	}
	queue<int> q;
	int dist = 0;
	int ans = 0;
	int root = 1;
	q.push(root);
	check[1] = true;
	while(!q.empty()) {
		
	}
	return 0;
}
/*
root -> most far
most far -> most far
*/
