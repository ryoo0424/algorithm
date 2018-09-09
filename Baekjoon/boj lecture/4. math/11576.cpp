#include<iostream>
#include<cmath>
using namespace std;
void convert (int _num, int _base) {
	if (_num == 0) return;
	convert(_num/_base, _base);
	cout << _num%_base << ' ';
}
int main() {
	int a, b, m, tmp, trans = 0;
	cin >> a >> b >> m;
	while (m--) {
		cin >> tmp;
		trans += tmp * (pow(a, m));
	}
	convert(trans, b);
	return 0;
}

