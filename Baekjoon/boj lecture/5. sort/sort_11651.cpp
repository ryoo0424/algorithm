#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
pair<int,int> a[100000];
int main() {
	//ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	/*
	for (int i=0; i<n; i++) cin >> a[i].second >> a[i].first;
	sort(a, a+n);
	for (int i=0; i<n; i++) cout << a[i].first << " " << a[i].second << endl;
	*/
	for (int i=0; i<n; i++) scanf("%d %d", &a[i].second, &a[i].first);
	sort(a, a+n);
	for (int i=0; i<n; i++) printf("%d %d\n", a[i].second, a[i].first);
	return 0;
}
