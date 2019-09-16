#include <iostream>

using namespace std;
int a[] = {3, 2, 5, 4, 1, 0};
void swap(int &a, int &b) {
	int tmp = a; a = b; b = tmp;
}

bool next_permutation() {
	int i = 5, j = 5;
	while (a[i-1] > a[i]) i--;
	if (i <= 0) return false;
	while (a[i-1] > a[j]) j--;
	swap(a[i-1], a[j]);
	j = 5;
	while (i < j) swap(a[i++], a[j--]);
	return true;
}

int main() {
	do {
		for (int i=0; i<6; i++) cout << a[i] << " ";
		cout << '\n';
	} while (next_permutation());
	
	
	return 0;
}
