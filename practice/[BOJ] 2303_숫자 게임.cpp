/*
	접근 방법
	1. 순열을 이용해서 각 참가자가 가지는 숫자의 조합중 최고점을 ans[i]에 저장
	2. 저장된 ans[i]를 전체 탐색하여 최고점을 가지는 가장 높은 번호 선수를 출력 
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
