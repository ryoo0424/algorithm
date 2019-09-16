#include <iostream>
#include <algorithm>

using namespace std;

typedef struct coord {
	int x, y, z;
} coord;

int n, m, k;
int matrix[50][50];
int tmp[50][50];
coord operation[6];

void copy() {
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			tmp[i][j] = matrix[i][j];
		}
	}
}

int calculate() {
	int sum = 987654321;
	for (int i=0; i<n; i++) {
		int cnt = 0;
		for (int j=0; j<m; j++) {
			cnt += tmp[i][j];
		}
		if (cnt < sum) sum = cnt;
	}
	return sum;
}

void rotate(int r, int c, int s) {
	for (int i=1; i<=s; i++) {
		int point = tmp[r-i][c-i];
		for (int j=r-i; j<r+i; j++) tmp[j][c-i] = tmp[j+1][c-i];	// 왼쪽 전부 위로 한 칸씩 
		for (int j=c-i; j<c+i; j++) tmp[r+i][j] = tmp[r+i][j+1];	// 아래쪽
		for (int j=r+i; j>r-i; j--) tmp[j][c+i] = tmp[j-1][c+i];	// 오른쪽
		for (int j=c+i; j>c-i+1; j--) tmp[r-i][j] = tmp[r-i][j-1];	// 위쪽 
		tmp[r-i][c-i+1] = point;									// 예외 처리 
	}
}

int main() {
	int ans = 987654321;
	
	cin >> n >> m >> k;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> matrix[i][j];
		}
	}
	
	for (int i=0; i<k; i++) {
		int a, b, c;	cin >> a >> b >> c;
		operation[i].x = a-1, operation[i].y = b-1, operation[i].z = c;
	}
	
	int order[6] = {0, 1, 2, 3, 4, 5};
	
	do {
		copy();
		for (int i=0; i<k; i++) {
			rotate(operation[order[i]].x, operation[order[i]].y, operation[order[i]].z);
		}
		if (calculate() < ans) ans = calculate();
	} while (next_permutation(order, order+k));
	
	cout << ans << '\n';
	
	return 0;
}
