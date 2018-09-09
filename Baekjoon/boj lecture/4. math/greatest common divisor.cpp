#include<iostream>
using namespace std;
int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
} // 재귀함수는 호출 횟수가 한 번일 경우 비재귀로 바꿀 수 있다
int gcd2(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main(){
	// 1.
	int a, b;
	cin >> a >> b;
	int m = min(a, b);
	int gcd = 1;
	for (int i=2; i<=m; i++) if (a % i == 0 && b % i == 0) gcd = i;
	cout << gcd;
	// 2. Euclidean algorithm
	// gcd(a, b) = gcd(b, r(=a%b))	
	return 0;
}
// 세 수의 최대공약수는 gcd(a, b, c) = gcd(gcd(a, b), c)와 같은 형태로 만들 수 있음 

