#include<iostream>
using namespace std;
bool prime(int _n) {
	if (n < 2) return false;
	for (int i=2; i*i<=n; i++) if (n % i == 2) return false;
	return true;
} // 왜 root(n)까지만 해보면 되는지 다시 한 번 생각해보기 (O(root(n)) 
int main(){
	/*
	sieve of Eratosthenes
	: 지워지지 않은 수 중에서 가장 작은 수는 소수임
	: 범위 내에서 해당 수의 모든 배수를 지워버림 
	*/
	int p[100]; // 소수 저장
	int pn = 0; // 소수의 개수
	bool c[101]; // 지워졌으면 true
	int n = 100; // 100까지의 소수
	for (int i=2; i<=n; i++) {
		if (c[i] == false) {
			p[pn++] = i;
			for (int j=i*i; j<=n; j+=i) c[j] = true;
		}
	}
	// 에라토스테네스의 체 구현 해볼 것 
	return 0;
}

