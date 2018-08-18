#include<iostream>
#include<algorithm>
#include<cstring>
#define MAX(x,y,z) ((x>y?x:y) > (y>z?y:z) ? (x>y?x:y) : (y>z?y:z))
using namespace std;
int d[100001][3];
int sticker[100001][2];
int main(void){
	int n, t;
	cin >> n;
	while(n--){
		memset(d, sizeof(int)*100001*3, 0);
		memset(sticker, sizeof(int)*100001*2, 0);
		cin >> t;
		for (int i=0; i<2; i++) {
			for (int j=1; j<=t; j++)	{
				scanf("%d", &sticker[j][i]);
			}
		}
		d[1][0] = 0, d[1][1] = sticker[1][0], d[1][2] = sticker[1][1];
		for (int i=2; i<=t; i++) {
			d[i][0] = MAX(d[i-1][0], d[i-1][1], d[i-1][2]);
			d[i][1] = max(d[i-1][0], d[i-1][2]) + sticker[i][0];
			d[i][2] = max(d[i-1][0], d[i-1][1]) + sticker[i][1];
		}
		cout << MAX(d[t][0], d[t][1], d[t][2]) << endl;
	}
	return 0;
}



/*
select Nth upper: max(N-1th lower, N-1th nothing) + Nth upper
select Nth lower: max(N-1th upper, N-1th nothing) + Nth lower
select Nth nothing: max(N-1th upper, N-1th lower, N-1th nothing)

==> max(d[n][0], d[n][1], d[n][2])

d[n][2]: d[n][0] -> xx, d[n][1] => xo, d[n][2] => ox
*/ 

