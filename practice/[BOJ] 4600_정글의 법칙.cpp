#include <iostream>
#include <vector>
#define P pair<int, int>
using namespace std;

int main() {
	int b, p;	cin >> b >> p;
	
	while (b != 0 && p != 0) {
		b = -b;
		vector<int> going[b], q(20, 0);
		vector<P> bridge;
		for (int i=0; i<b; i++) {
			int c, t;	cin >> c >> t;
			bridge.push_back(P(c, t));
		}
		for (int i=0; i<b; i++) {
			for (int j=0; j<bridge[i].first; j++) {
				going[i].push_back(0);
			}
		}
		int cnt = 0, time = 0;
		q[0] = p;
		while (cnt < p) {
			for (int i=0; i<b; i++) {
				bool flag = false;
				for (int j=0; j<going[i].size(); j++) if (going[i][j] > 0) flag = true;
				if (flag) continue;
				for (int j=0; j<going[i].size(); j++) {	// i번 다리에 사람 집어넣기
					if (going[i][j] == 0 && q[i] > 0) {
						going[i][j] = bridge[i].second;
						q[i] -= 1;
					}
				}
			}
			for (int i=0; i<b; i++) {
				for (int j=0; j<going[i].size(); j++) {	// i번 다리에서 사람 빼고 다음 큐에 넣기 
					if (going[i][j] > 0) {
						going[i][j] -= 1;
						if (going[i][j] == 0) {
							if (i + 1 == b) cnt += 1;
							else q[i+1] += 1;
						}
					}
				}
			}
			
			time += 1;
//			
//			cout << "(" << cnt << ", " << time << ")\n";
//			for (int i=0; i<b; i++) {
//				cout << "Bridge [" << i << "] ";
//				for (int j=0; j<going[i].size(); j++) {
//					cout << going[i][j] << " ";
//				}
//				cout << '\n';
//			}
//			cout << '\n';
		}
		cout << time << '\n';
		cin >> b >> p;
	}
	
	return 0;
}
