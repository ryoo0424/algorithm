#include<cstdio>
long long d[91];
int main(void){
	d[1] = 1;
	d[2] = 1;
	int n;
	scanf("%d", &n);
	if (n <= 2) printf("%d\n", d[n]);
	else {
		for (int i=3; i<=n; i++) d[i] = d[i-1] + d[i-2];
		printf("%lld\n", d[n]);
	}
	return 0;
}
/*
d[n] = d[n-1](�������� 0�� ���) 
d[n] = d[n-2](�������� 1�� ��� ������ 0�̾�� �ϹǷ� d[n-1] = d[n-2]) 
*/
