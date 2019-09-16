/*
	���� ���
	1. ����� �밢�����θ� ������ �� �ִ� = ü���� ������ �ٴ� ���� �ٸ� ������ �� �� ����.
	2. ���� i, j ��ǥ�� �������� black�� white�� ���� ���Ϳ� ������ �� �� �� ��Ʈ��ŷ�� ����
	3. ����� ���ļ� ��� 
*/
#include <iostream>
#include <vector>
#define P pair<int,int>
using namespace std;

int n, sumw, sumb;
int map[10][10];
int org[10][10];

void copy() {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			map[i][j] = org[i][j];
		}
	}
}

void solve(vector<P> v, int idx, int cnt, int &sum) {
	if (idx == v.size()) {
		if (cnt > sum) sum = cnt;
		return;
	}
	
	bool flag = true;
	int r = v[idx].first, c = v[idx].second;
	
	while (r >= 0 && c >= 0) r--, c--;
	while (r < n && c < n) if (map[r++][c++] == 2) flag = false;
	
	r = v[idx].first, c = v[idx].second;
	
	while (r >= 0 && c < n) r--, c++;
	while (r < n && c >= 0) if (map[r++][c--] == 2) flag = false;
	
	if (flag) {
		map[v[idx].first][v[idx].second] = 2;
		solve(v, idx+1, cnt+1, sum);
		map[v[idx].first][v[idx].second] = 0;
		solve(v, idx+1, cnt, sum);
	} else solve(v, idx+1, cnt, sum);
}

int main() {
	vector<P> black, white;
	cin >> n;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> org[i][j];
			if (org[i][j] == 1) {
				if ((i + j) % 2) white.push_back(P(i, j));
				else black.push_back(P(i, j));
			}
		}
	}
	copy();
	solve(white, 0, 0, sumw);
	copy();
	solve(black, 0, 0, sumb);
	
	cout << sumw + sumb << '\n';
	
	return 0;
}
