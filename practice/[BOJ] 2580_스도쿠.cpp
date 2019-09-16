/*
	���� ���
	1. 9*9 for���� �׳� ���鼭 0�� ��츦 Ž���ϸ� �ð��ʰ�
	2. vector�� 0�� ��ǥ�� ���� �� �ش� vector�� �ε����� ���
	3. ��Ʈ��ŷ 
*/
#include <iostream>
#include <vector>
#define P pair<int,int>
using namespace std;

int board[9][9];
int ans[9][9];
vector<P> v;
bool flag = false;

void solve(int idx, int cnt) {
	if (cnt == 81) {
		for (int i=0; i<9; i++) {
			for (int j=0; j<9; j++) {
				ans[i][j] = board[i][j];
			}
		}
		flag = true;
		return;
	}
	
	if (flag) return;
	
	int r = v[idx].first;
	int c = v[idx].second;
	
	bool check[10] = {false};
	for (int k=0; k<9; k++) if (board[k][c] != 0) check[board[k][c]] = true;	// ���� 
	for (int k=0; k<9; k++) if (board[r][k] != 0) check[board[r][k]] = true;	// ���� 
	for (int x=(r/3)*3; x<(r/3)*3+3; x++) {
		for (int y=(c/3)*3; y<(c/3)*3+3; y++) {
			if (board[x][y] != 0) check[board[x][y]] = true;					// �׸�	
		}
	}
	
	for (int k=1; k<=9; k++) {
		if (!check[k]) {
			board[r][c] = k;
			solve(idx+1, cnt+1);
			board[r][c] = 0;
		}
	}
}

int main() {
	int cnt = 0;
	
	for (int i=0; i<9; i++) {
		for (int j=0; j<9; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0) cnt += 1;
			else v.push_back(P(i, j));
		}
	}
	
	solve(0, cnt);
	
	for (int i=0; i<9; i++) {
		for (int j=0; j<9; j++) {
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}
	
	return 0;
}
