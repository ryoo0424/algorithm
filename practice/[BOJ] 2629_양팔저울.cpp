#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	bool check[30][15001];
	int weight[30];
	int n;	cin >> n;
	
	for (int i=0; i<n; i++) {
		cin >> weight[i];
		check[i][weight[i]] = true;
	}
	
	int t;	cin >> t;
	
	for (int i=0; i<n; i++) {
		
	}
	
	for (int i=0; i<t; i++) {
		int target;	cin >> target;
//		cout << (dfs(target, n-1) ? "Y " : "N ");
	}
	
	return 0;
}
