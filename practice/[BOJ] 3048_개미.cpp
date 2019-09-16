#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void swap(int &a, int &b) {
	int tmp = a; a = b; b = tmp;
}
int main() {
	int n1, n2, t;
	char g1[100], g2[100], ant[100];
	int group[26] = {0};
	cin >> n1 >> n2 >> g1 >> g2 >> t;
	for (int i=0; i<n1; i++) {
		ant[i] = g1[n1-i-1];
		group[ant[i]-'A'] = 1;
	}
	for (int i=0; i<n2; i++) {
		ant[i+n1] = g2[i];
		group[g2[i]] = 2;
	}
	ant[n1+n2] = '\0';
	for (int i=1; i<=t; i++) {
		int pivot = abs(i - n1);
		for (int j=1; j<=i; j++) {
			if (pivot > n1+n2-2) break;
			if (group[ant[pivot]-'A'] != group[ant[pivot+1]-'A']) {
				swap(ant[pivot], ant[pivot+1]);
				pivot += 2;
			}
		}
	}
	cout << ant << '\n';
	return 0;
}
