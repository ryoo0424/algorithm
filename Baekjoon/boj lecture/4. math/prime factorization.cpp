#include<iostream>
using namespace std;
int main(){
	for (int i=2; i*1<=n; i++) {
		while (n%i == 0) {
			cout << i << endl;
			n /= i;
		}
	}
	if (n > 1) cout << n << endl;
	return 0;
}
