#include <iostream>

using namespace std;

void swap(int &a, int &b) {
	int tmp = a; a = b; b = tmp;
}

pair<int,int> find(int a[], int n) {
	for (int i=1; i<=n; i++) {
		if (a[i] != i) {
			for (int j=i; j<=n; j++) {
				if (a[j] == i) {
					int x = i, y = j;
					while (x < y) swap(a[x++], a[y--]);
					return make_pair(i, j);
				}
			}
		}
	}
}

pair<int,int> findr(int a[], int n) {
	for (int i=n; i>=0; i--) {
		if (a[i] != i) {
			for (int j=i; j>=0; j--) {
				if (a[j] == i) {
					int x = i, y = j;
					while (x > y) swap(a[x--], a[y++]);
					return make_pair(j, i);
				}
			}
		}
	}
}

bool done(int a[], int n) {
	for (int i=1; i<=n; i++) if (a[i] != i) return false;
	return true;
}

int main() {
	int a[10001];
	int b[10001];
	int n;	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	pair<int,int> ans1, ans2;
	if (done(a, n)) {
		ans1 = make_pair(1, 1);
		ans2 = make_pair(n, n);
	} else {
		ans1 = find(a, n);
		if (done(a, n)) ans2 = make_pair(n, n);
		else ans2 = find(a, n);
		if (!done(a, n)) {
			ans1 = findr(b, n);
			if (done(b, n)) ans2 = make_pair(1, 1);
			else ans2 = findr(b, n);
		}
	}
	cout << ans1.first << " " << ans1.second << '\n' << ans2.first << " " << ans2.second << '\n';
	return 0;
}
