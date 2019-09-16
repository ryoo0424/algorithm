/*
	���� ���
	1. ������ �̿��ؼ� �� �����ڰ� ������ ������ ������ �ְ����� ans[i]�� ����
	2. ����� ans[i]�� ��ü Ž���Ͽ� �ְ����� ������ ���� ���� ��ȣ ������ ��� 
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;	cin >> n;
	int gamer[1000][5];
	int ans[1000] = {0};
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<5; j++) {
			cin >> gamer[i][j];
		}
	}
	
	for (int i=0; i<n; i++) {
		int order[5] = {0, 0, 1, 1, 1};
		
		do {
			int tmp = 0;
			for (int j=0; j<5; j++) if (order[j]) tmp += gamer[i][j];
			tmp %= 10; 
			if (tmp > ans[i]) ans[i] = tmp;
		} while (next_permutation(order, order+5));
	}
	
	int highest = 0, winner;
	
	for (int i=0; i<n; i++) {
		if (highest <= ans[i]) {
			highest = ans[i];
			winner = i + 1;
		}
	}
	
	cout << winner << '\n';
	
	return 0;
}
