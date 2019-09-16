#include <cstdio>
#include <algorithm>
#include <vector> 
#include <cstring>

using namespace std;

int n, m, c;
int order[100] = {0, };
int bucket[10][10] = {0, };

int calc(int idx) {
	int ret = 0;
	
	for (int i=1; i<=m; i++) {
		vector<int> v;
		
		for (int k=1; k<=m-i; k++) v.push_back(0);
		for (int k=m-i; k<=m; k++) v.push_back(1);
	
		do {
			int tot = 0, sum = 0;
			bool flag = false;
			
			for (int k=0; k<m; k++) {
				if (v[k] == 1) tot += bucket[idx/n][idx%n + k];
				if (tot > c) flag = true;
			}
			
			if (flag) continue;		
			
			for (int k=0; k<m; k++) {
				if (v[k] == 1) sum += bucket[idx/n][idx%n + k] * bucket[idx/n][idx%n + k];
			}
			
			if (sum > ret) ret = sum;
		} while (next_permutation(v.begin(), v.end()));
	}
	return ret;
}

int main() {
	int t;	scanf("%d", &t);
	for (int x=1; x<=t; x++) {
		int ans = 0;
		
		memset(order, 0, sizeof(order));
		memset(bucket, 0, sizeof(bucket));
		
		scanf("%d %d %d", &n, &m, &c);
		order[n*n-1] = order[n*n-2] = 1;
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				scanf("%d", &bucket[i][j]);
			}
		}
		
		do { // ������ �� ���� �׷� ã��
			int idx1, idx2;			
			
			for (int i=0; i<n*n; i++) {
				if (order[i] == 1) {
					idx1 = i;
					break;
				}
			}
			
			if (idx1 / n != (idx1 + m - 1) / n) continue;	// �����ִ� ���  
			
			for (int i=idx1+1; i<n*n; i++) {
				if (order[i] == 1) {
					idx2 = i;
					break;
				}
			}
			
			if (idx2 / n != (idx2 + m - 1) / n) continue;	// �����ִ� ��� 
			if (idx2 - idx1 < m) continue;					// �׷��� ��ġ�� ���
			if (idx2 + m - 1 > n * n - 1) continue;			// �� ��° �׷��� ������ ����� ���
			// �� �׷쿡�� ���ǿ� �´� �ִ� ���� ���
			int sum1 = calc(idx1);
			int sum2 = calc(idx2);
			
			if (sum1 + sum2 > ans) ans = sum1 + sum2;
		} while (next_permutation(order, order+n*n));

		printf("#%d %d\n", x, ans);
	}
	
	return 0;
}
