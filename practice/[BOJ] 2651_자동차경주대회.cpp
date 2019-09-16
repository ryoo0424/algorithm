/*
	접근 방법
	1. d[i]의 의미 : i번 정비소에 최소 시간으로 방문
	2. d[i] 로직 : i-1번 이하 번호의 정비소(=d[j]) &&
					d[i]에서 최대 거리 내로 도달할 수 있는 정비소 중
					d[j]가 가장 작은 정비소를 골라 d[j]+repair[i]가 d[i]보다 작으면 d[i]를 갱신
					갱신된 경우 그 값과 j를 d에 저장 
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
