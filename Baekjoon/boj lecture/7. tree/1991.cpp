#include<iostream>
using namespace std;
char a[26][2];
void pre(int node) {
	if (node == -1) return;
	cout << (char)(node+'A');
	pre(a[node][0]);
	pre(a[node][1]);
}
void in(int node) {
	if (node == -1) return;
	in(a[node][0]);
	cout << (char)(node+'A');
	in(a[node][1]);
}
void post(int node) {
	if (node == -1) return;
	post(a[node][0]);
	post(a[node][1]);
	cout << (char)(node+'A');
}
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		char p, l, r;
		cin >> p >> l >> r;
		p = p - 'A';
		if (l == '.') a[p][0] = -1;
		else a[p][0] = l - 'A';
		if (r == '.') a[p][1] = -1;
		else a[p][1] = r - 'A';
	}
	pre(0); cout << endl;
	in(0); cout << endl;
	post(0); cout << endl;
	return 0;
}
