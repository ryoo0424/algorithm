#include<iostream>
using namespace std;
int s[300], ��;
int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> s[i];
	
	return 0;
}
/*
d[i][1]=1�� ����: i-1��° ����� ������ �ȵ� -> max(d[i-2][1], d[i-2][2]) + s[i]
d[i][2]=2�� ����: d[i-1][1] + a[i]
*/
