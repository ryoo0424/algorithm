/*
	���� ���
	1. d[i]�� �ǹ� : i�� ����ҿ� �ּ� �ð����� �湮
	2. d[i] ���� : i-1�� ���� ��ȣ�� �����(=d[j]) &&
					d[i]���� �ִ� �Ÿ� ���� ������ �� �ִ� ����� ��
					d[j]�� ���� ���� ����Ҹ� ��� d[j]+repair[i]�� d[i]���� ������ d[i]�� ����
					���ŵ� ��� �� ���� j�� d�� ���� 
*/
#include <iostream>
#include <vector>
using namespace std;
struct P {
	int first, second;
	P(){}
	P(int first, int second) : first(first), second(second) {}
};
int main() {
	int runnable, n;
	int distance[102] = {0}, repair[102] = {0};
	P d[102] = {P(0, 0)};	// first : minimum repair time, second : prior repair shop
	cin >> runnable >> n;
	for (int i=1; i<=n+1; i++) {
		cin >> distance[i];
		distance[i] += distance[i-1];
	}
	for (int i=1; i<=n; i++) cin >> repair[i];
	for (int i=1; i<=n+1; i++) {
		d[i] = P(d[i-1].first + repair[i], i-1);
		for (int j=i-1; j>=0 && distance[i] - distance[j] <= runnable; j--) {
			if (d[j].first + repair[i] < d[i].first) d[i] = P(d[j].first + repair[i], j);
		}
	}
	
	vector<int> ans;
	
	int now = d[n+1].second;
	
	while (now != 0) {
		ans.push_back(now);
		now = d[now].second;
	}
	
	cout << d[n+1].first << '\n' << ans.size() << '\n';
	for (int i=ans.size()-1; i>=0; i--) cout << ans[i] << " ";
	
	return 0;
}
