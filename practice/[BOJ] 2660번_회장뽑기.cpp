/*
	���� ���
	1. bfs�� ���鼭 q.front()�� ����� ���� �ĺ�(src)�� �������� ��� ģ���� üũ�� ��� �ش� depth ���
	2. ��� ģ���� üũ���� ���� ��� src�� ģ������ �ٽ� Ž���ϸ�, �� �� depth�� src�� depth+1�� ����
	3. ��� �ĺ��ڿ� ���� 1-2�� �ݺ��Ͽ� �ش� �ĺ����� depth�� pair�� ���� 
	4. �������� �䱸�ϴ� �������� ans�� �����Ͽ� ��� 
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct P { 
	int first, second;
	P() {}
	P(int a, int b) : first(a), second(b) {}
};

vector<int> v[51];
vector<P> ans;

bool operator <(const P a, const P b) {
	return a.first == b.first ? a.second < b.second : a.first < b.first;
}

int bfs(int cand, int n) {
	int check[51] = {0};
	queue<int> q;
	q.push(cand);
	check[cand] = 1;
	while (!q.empty()) {
		int src = q.front();
		int ret = 0;
		bool flag = true;
		for (int i=1; i<=n; i++) {
			if (check[i] == 0) flag = false;
			ret = max(ret, check[i]);
		}
		if (flag) return ret;
		q.pop();
		for (int i=0; i<v[src].size(); i++) {
			if (check[v[src][i]] == 0) {
				q.push(v[src][i]);
				check[v[src][i]] = check[src] + 1;
			}
		}
	}
}

int main() {
	int cand, buddy, n;	cin >> n >> cand >> buddy;
	
	while (cand != -1 && buddy != -1) {
		v[cand].push_back(buddy);
		v[buddy].push_back(cand);
		cin >> cand >> buddy;
	}
	
	for (int i=1; i<=n; i++) {
		ans.push_back(P(bfs(i, n), i));
	}
	
	sort(ans.begin(), ans.end());
		
	int cnt = 1;
	
	while (cnt < ans.size() && ans[cnt-1].first == ans[cnt].first) cnt += 1;
	
	cout << ans[0].first - 1 << " " << cnt << '\n';
	for (int i=0; i<cnt; i++) {
		cout << ans[i].second << " ";
	}
	
	return 0;
}
