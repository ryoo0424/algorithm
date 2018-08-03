#include<stdio.h>

#define max(a, b, c) a > b ? ((a > c) ? a : c) : ((b > c) ? b : c)

int main(){
	int N, wine[10000], dp[3][10000], flag = 0;
	scanf("%d", &N);
	for(int i=0;i<N;i++) 
		scanf("%d", &wine[i]);
	
	/*
	각 잔마다
	1. 마시지 못하는 경우: 이전에 연속으로 두 잔을 마신 경우 
	2. 마시는 경우: 이전에 한 잔만 마셨거나 마시지 않은 경우 
	3. 마시지 않는 경우: 이전에 한 잔만 마셨거나 마시지 않은 경우 
	*/
	
	/*
	1. 마지막 n번 째 포도주 잔: 마시지 않는 경우
		> dp[n] = dp[n-1]
	2. 마지막 n번 째 포도주 잔: 1잔 째 마신 경우
		> dp[n] = dp[n-2] + wine[n]
	3. 마지막 n번 째 포도주 잔: 2잔 째 마신 경우
		> dp[n] = dp[n-3] + wine[n-1] + wine[n]
		
	max(1, 2, 3);
	
	http://stack07142.tistory.com/44
	*/
	
	dp[0][0] = 0;
	dp[1][0] = wine[0]; flag[1]++;
	dp[2][0] = 0;
	
	for(int i=1;i<N;i++){
		dp[0][i] = 		
	}
	
	return 0;
}
