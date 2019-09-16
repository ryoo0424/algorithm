/*
	���� ���
	1. �ܾ� ���̰� ���� ��, ��ü ���� �� �ٸ� �κ��� 2�� �����̸� ����� �ܾ�
	2. �ܾ� ���� ���̰� 1�� ��, ��ü ���� �� �ٸ� �κ��� 1�� �����̸� ����� �ܾ�
	3. �� �ܿ��� �ٸ� �ܾ� 
*/	
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int target[26] = {0};
	int n, ans = 0;	cin >> n;
	char org[11];	cin >> org;
	for (int i=0; i<strlen(org); i++) target[org[i]-'A'] += 1;
	for (int i=0; i<n-1; i++) {
		char tmp[11];	cin >> tmp;
		int lendiff = abs((int)strlen(org) - (int)strlen(tmp));
		if (lendiff > 1) continue;
		int diff = 0, compare[26] = {0};
		for (int j=0; j<strlen(tmp); j++) compare[tmp[j]-'A'] += 1;
		for (int j=0; j<26; j++) if (target[j] != compare[j]) diff += abs(target[j] - compare[j]);
		if (lendiff == 0 && diff <= 2) ans += 1;
		else if (lendiff == 1 && diff <= 1) ans += 1;
	}
	
	cout << ans << '\n';

	return 0;
}
