#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 4. ������ �����ε� ����: 3�� ° ���� �ʿ� ����
struct Point {
	int x, y;
	bool operator < (const Point &v /*v���� &�� �� �پ�� ��*/ const {
		if (x < v.x) return true;
		else if (x == v.x) return y < v.y;
		else return false;
	}
}
int main() {
	// 1. (x, y)�� ���� �� x�� �����ϴ� ������, ������ y�� �����ϴ� ������ ����
	int n;
	cin >> n;
	vector< pair<int,int> > a(n);
	for (int i=0; i<n; i++) cin >> a[i].first >> a[i].second; 
	sort(a.begin(), a.end());
	for (int i=0; i<a.size(); i++) cout << a[i].first << a[i].second;
	// ��ǥ ������ pair ���İ� ������ �Ȱ��� ������ �׳� pair ���� ���ϴ� 
	
	// 3. ���Լ��� ����� ��� 3�� ° ���ڷ� �Լ� �̸��� �Ѱ��־�� �Ѵ�
	sort(a.begin(), a.end(), cmp);
	// C++11? �̻���ʹ� ���� ��� ����
	 
	return 0;
}
// 2. �ٸ� ���
bool cmp (const Point &u, const Point &v) {
	if (u.x < v.x) return true;
	else if (u.x == v.x) return u.y < v.y;
	else return false;
}
 
