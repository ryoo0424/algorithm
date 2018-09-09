#include<iostream>
using namespace std;
int s[300], ㅇ;
int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> s[i];
	
	return 0;
}
/*
d[i][1]=1개 연속: i-1번째 계단은 밟으면 안됨 -> max(d[i-2][1], d[i-2][2]) + s[i]
d[i][2]=2개 연속: d[i-1][1] + a[i]
*/
