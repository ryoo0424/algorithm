/*
	접근 방법
	1. N개 노드에 N-1개 엣지가 있다 = 사이클이 없다
	2. 로봇1에서 로봇2로 dfs를 통해 경로를 찾아가며 경로가 추가될 때 그 경로의 길이를 저장
	3. 로봇2를 찾았을 때 ans에 저장된 모든 경로 중 가장 긴 경로를 빼서 출력 
*/

#include <iostream>
#include <vector>
#define P pair<int, int>
using namespace std;

int ret = 987654321; 
vector<int> ans;
vector<P> cave[100001];
bool check[100001];

void dfs(int st, int ed) {
	if (ed == st) {
		int sum = 0, x = 0;
		for (int i=0; i<ans.size(); i++) {
			sum += ans[i];
			if (x < ans[i]) x = ans[i];
		}
		if (sum - x < ret) ret = sum - x;
		return;
	}
	for (int i=0; i<cave[st].size(); i++) {
		if (!check[cave[st][i].first]) {
			check[st] = true;
			ans.push_back(cave[st][i].second);
			dfs(cave[st][i].first, ed);
			ans.pop_back();
			check[st] = false;
		}
	}
}

int main() {
	int n, r1, r2;	cin >> n >> r1 >> r2;
	
	for (int i=0; i<n-1; i++) {
		int u, v, d;	cin >> u >> v >> d;
		cave[u].push_back(P(v, d));
		cave[v].push_back(P(u, d));
	}
	
	dfs(r1, r2);
	
	cout << ret << '\n';
	
	return 0;
}
