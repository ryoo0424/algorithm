#include <algorithm>
#include <iostream>
#include <vector>
#define P pair<int, int>
using namespace std;

int main() {
	int room[10][10];
	
	int t;	cin >> t;
	
	for (int tc=1; tc<=t; tc++) {
		vector<P> people, stair;
		
		int n, ans = 987654321;	cin >> n;
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				cin >> room[i][j];
				if (room[i][j] == 1) people.push_back(P(i, j));
				if (room[i][j] > 1) stair.push_back(P(i, j));
			}
		}
		
		for (int h=0; h<=people.size(); h++) {
			vector<int> order;
			
			for (int g=0; g<h; g++) order.push_back(0);
			for (int g=h; g<people.size(); g++) order.push_back(1);
			
			for (int i=0; i<order.size(); i++) cout << order[i] << " "; cout << '\n';
			
			do {
				for (int i=0; i<people.size(); i++) {
					vector<int> go[2];
					
					for (int j=0; j<people.size(); j++) go[order[j]].push_back(abs(people[j].first - stair[order[j]].first) + abs(people[j].second - stair[order[j]].second));
					
//					for (int j=0; j<i; j++) go[0].push_back(abs(people[j].first - stair[0].first) + abs(people[j].second - stair[0].second));
//					for (int j=i; j<people.size(); j++) go[1].push_back(abs(people[j].first - stair[1].first) + abs(people[j].second - stair[1].second));
//				
					sort(go[0].begin(), go[0].end());
					sort(go[1].begin(), go[1].end());
	//				cout << "STAIR 1 #############################\n";
					// 1번 계단 처리
					int t1 = 0, t2 = 0, size = 0, waiting = 0, cnt = 0;
					bool check1[10] = {false};
					while (cnt < go[0].size()) {
						for (int j=0; j<go[0].size(); j++) if (go[0][j] > 0) go[0][j] -= 1;
						for (int j=0; j<go[0].size(); j++) {
							if (go[0][j] == 0) {
								if (waiting > j && j >= cnt) {
									cnt += 1;
									size -= 1;
									continue;
								}
								if (waiting <= j) {
									if (size < 3) {
										if (check1[j] == false) go[0][j] += 1;
										go[0][j] += room[stair[0].first][stair[0].second];
										size += 1, waiting += 1;
									} else {
										check1[j] = true;
									}
								} 
							}
						}
						t1 += 1;
	//					cout << "1 : ";	for (int y=0; y<go[0].size(); y++) cout << go[0][y] << " ";	cout << "[" << t1 << "]\n";
					}
	//				for (int j=0; j<go[0].size(); j++) cout << check1[j] << " ";	cout << '\n';
	//				cout << "STAIR 2 #############################\n";
					// 2번 계단 처리 
					size = 0, waiting = 0, cnt = 0;
					bool check2[10] = {false};
					while (cnt < go[1].size()) {
						for (int j=0; j<go[1].size(); j++) if (go[1][j] > 0) go[1][j] -= 1;
						for (int j=0; j<go[1].size(); j++) {
							if (go[1][j] == 0) {
								if (waiting > j && j >= cnt) {
									cnt += 1;
									size -= 1;
									continue;
								}
								if (waiting <= j) {
									if (size < 3) {
										if (check2[j] == false) go[1][j] += 1;
										go[1][j] += room[stair[1].first][stair[1].second];
										size += 1, waiting += 1;
									} else {
										check2[j] = true;
									}
								} 
							}
						}
						t2 += 1;
	//					cout << "2 : ";	for (int y=0; y<go[1].size(); y++) cout << go[1][y] << " ";	cout << "[" << t2 << "]\n";
					}
					
					int result = max(t1, t2);
					
					ans = min(ans, result);
				}

			} while (next_permutation(order.begin(), order.end()));
		}
		
				
		cout << "#" << tc << " " << ans << '\n';
	}
	
	return 0;
}
