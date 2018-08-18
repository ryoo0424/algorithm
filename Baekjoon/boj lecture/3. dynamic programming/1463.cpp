#include<iostream>
#include<cstring>
using namespace std;
int d[1000001]; //d[N] = N=>1로 만드는 데 필요한 연산의 최솟값 
int go(int n);
int main(){
	int n;
	cin >> n;
	
	cout << go(n);
	return 0;
}
int go(int n) {
	if (n == 1) return 0;
	if (d[n] > 0) return d[n];
	d[n] = d[n-1] + 1 ;
	if (n%2 == 0) {
		int temp = go(n/2) + 1;
		if (d[n] > temp) d[n] = temp;
	}
	if (n%3 == 0) {
		int temp = go(n/3) + 1;
		if (d[n] > temp) d[n] = temp;
	}
	return d[n];
}
int go2(int n) {
	for (int i=2; i<=n; i++) {
		d[i] = d[i-1] + 1;
		if (i%2 == 0 && d[i] > d[i/2] + 1) d[i] = d[i/2] + 1;
		if (i%3 == 0 && d[i] > d[i/3] + 1) d[i] = d[i/3] + 1;
	}
}
