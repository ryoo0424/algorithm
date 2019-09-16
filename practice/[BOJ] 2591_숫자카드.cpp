#include <iostream>

using namespace std;

int main() {
	int a, b, c, n;	cin >> a >> b >> c >> n;
	
	int A = n/a, B = n/b, C = n/c;
	
	int ans = 0;
	
	for (int i=0; i<=A; i++) {
		for (int j=0; j<=B; j++) {
			for (int k=0; k<=C; k++) {
				if (i * a + j * b + k * c == n) ans = 1;
			}
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
