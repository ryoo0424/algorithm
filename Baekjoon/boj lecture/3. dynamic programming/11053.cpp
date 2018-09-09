#include<iostream>
using namespace std;
int d[1000], a[1000];
int main(){
	int n, ans = 1;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++) {
		d[i] = 1;
		for (int j=i-1; j>=0; j--) {
			if (a[j] < a[i] && d[j] >= d[i]) d[i] = d[j] + 1;
			if (ans < d[i]) ans = d[i];
		}
	}
	cout << ans << endl;
	return 0;
}
/*


*/

/*
d[i] = a[1], ... , a[i]������ ������ ���� �� a[i]�� ���������� �ϴ�
���� �� �����ϴ� �κ� ������ ���� 
d[i]�� a[i]�� �ݵ�� ���ԵǾ�� �Ѵ�
d[i] = max(d[j]) + 1, j<i, a[j] < a[i] 
*/
