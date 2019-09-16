/*
	접근 방법
	1. 1반부터 5반까지 순서대로 탐색하면서 각 반의 번호를 인덱스로 하는 벡터에 각 반에 속하는 학생의 번호를 넣는다. 
	2. ans[i][j]에 i번 학생과 같은 반인 j 학생 모두를 체크한다.
	3. 각 i마다 체크된 j의 수를 세어 최대가 되는 학생을 찾는다.
	4. 최대값을 갖는 여러 학생이 있을 때를 대비해 i를 n-1부터 찾는다. 
*/
#include <iostream>
#include <vector>
using namespace std;

bool ans[1000][1000];
int student[1000][5];

int main() {
	int n;	cin >> n;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<5; j++) {
			cin >> student[i][j];
		}
	}
	
	for (int j=0; j<5; j++) {
		vector<int> v[10];
		for (int i=0; i<n; i++) v[student[i][j]].push_back(i);
		for (int i=1; i<=9; i++) {
			for (int k=0; k<v[i].size(); k++) {
				for (int l=0; l<v[i].size(); l++) {
					ans[v[i][k]][v[i][l]] = true;
				}
			}
		}
	}
	
	int ret = 0, captain;
	
	for (int i=n-1; i>=0; i--) {
		int sum = 0;
		for (int j=n-1; j>=0; j--) if (ans[i][j]) sum += 1;
		if (sum >= ret) {
			ret = sum;
			captain = i + 1;
		}
	}
	
	cout << captain << '\n';
	
	return 0;
}
