#include <iostream>
#include <cstring>
using namespace std;
const int MAX_N = 1000*1000*1000;
int n;
unsigned char sieve[(MAX_N+7)/8];
// judge k == prime
inline bool isPrime(int k) {
	return sieve[k>>3] & (1<<(k&7));
}
// check k != prime
inline void setComposite(int k) {
	sieve[k>>3] &= ~(1<<(k&7));
}
// eratosthenes' sieve with bitmask
void era() {
	memset(sieve, 255, sizeof(sieve));
	setComposite(0);
	setComposite(1);
	for (int i=2; i*i<=n; i++) {
		if (isPrime(i)) {
			for (int j=i*i; i<=n; j+=i) {
				setComposite(j);
			}
		}
	}
}
int main() {
	era();
	cout << isPrime(3289123);
	return 0;
}
