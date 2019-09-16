/*
	���� ���
	1. �������� ���� ���� ũ�⸦ (ū��, ������) ������ �Է¹��� �� �������� ����
	2. dp�� ���� ���������� Ž���Ͽ� �ִ� �� ã�� 
*/
#include <iostream>
#include <algorithm>
using namespace std;
struct P {
	int first, second;
	P(){}
	P(int first, int second):first(first), second(second){}
};
void swap(int &a, int &b) {
	int tmp = a; a = b; b = tmp;	
}
bool operator < (const P a, const P b) {
	return a.first == b.first ? a.second > b.second : a.first > b.first;
}
int main() {
	P paper[100];
	int d[100] = {0};
	int n;	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> paper[i].first >> paper[i].second;
		if (paper[i].first < paper[i].second) swap(paper[i].first, paper[i].second);
	}
	sort(paper, paper+n);
	d[0] = 1;
	int ans = 0;
	for (int i=1; i<n; i++) {
		d[i] = 1;
		for (int j=i-1; j>=0; j--) {
			if (paper[j].first >= paper[i].first && paper[j].second >= paper[i].second && d[j] + 1 > d[i]) d[i] = d[j] + 1;
			if (d[i] > ans) ans = d[i];
		}
	}
	cout << ans << '\n';
	return 0;
}
