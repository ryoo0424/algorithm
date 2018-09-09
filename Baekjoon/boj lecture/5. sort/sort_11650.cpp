#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 4. 연산자 오버로딩 가능: 3번 째 인자 필요 없음
struct Point {
	int x, y;
	bool operator < (const Point &v /*v앞의 &가 꼭 붙어야 함*/ const {
		if (x < v.x) return true;
		else if (x == v.x) return y < v.y;
		else return false;
	}
}
int main() {
	// 1. (x, y)가 있을 때 x가 증가하는 순으로, 같으면 y가 증가하는 순으로 정렬
	int n;
	cin >> n;
	vector< pair<int,int> > a(n);
	for (int i=0; i<n; i++) cin >> a[i].first >> a[i].second; 
	sort(a.begin(), a.end());
	for (int i=0; i<a.size(); i++) cout << a[i].first << a[i].second;
	// 좌표 정렬은 pair 정렬과 조건이 똑같기 때문에 그냥 pair 쓰면 편하다 
	
	// 3. 비교함수를 만드는 경우 3번 째 인자로 함수 이름을 넘겨주어야 한다
	sort(a.begin(), a.end(), cmp);
	// C++11? 이상부터는 람다 사용 가능
	 
	return 0;
}
// 2. 다른 방법
bool cmp (const Point &u, const Point &v) {
	if (u.x < v.x) return true;
	else if (u.x == v.x) return u.y < v.y;
	else return false;
}
 
