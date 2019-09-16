/*
	접근 방법
	1. 단어 길이가 같을 때, 전체 구성 중 다른 부분이 2개 이하이면 비슷한 단어
	2. 단어 길이 차이가 1일 때, 전체 구성 중 다른 부분이 1개 이하이면 비슷한 단어
	3. 그 외에는 다른 단어 
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
