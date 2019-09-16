/*
	���� ���
	1. N�� ��忡 N-1�� ������ �ִ� = ����Ŭ�� ����
	2. �κ�1���� �κ�2�� dfs�� ���� ��θ� ã�ư��� ��ΰ� �߰��� �� �� ����� ���̸� ����
	3. �κ�2�� ã���� �� ans�� ����� ��� ��� �� ���� �� ��θ� ���� ��� 
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
