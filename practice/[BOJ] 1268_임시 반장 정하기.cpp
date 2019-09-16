/*
	���� ���
	1. 1�ݺ��� 5�ݱ��� ������� Ž���ϸ鼭 �� ���� ��ȣ�� �ε����� �ϴ� ���Ϳ� �� �ݿ� ���ϴ� �л��� ��ȣ�� �ִ´�. 
	2. ans[i][j]�� i�� �л��� ���� ���� j �л� ��θ� üũ�Ѵ�.
	3. �� i���� üũ�� j�� ���� ���� �ִ밡 �Ǵ� �л��� ã�´�.
	4. �ִ밪�� ���� ���� �л��� ���� ���� ����� i�� n-1���� ã�´�. 
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
