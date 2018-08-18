#include<cstdio>
int d[12];
int add(int _n){
	if (_n <= 3) return d[_n];
	for (int i=4; i<=_n ;i++) d[i] = d[i-1] + d[i-2] +d[i-3];
	return d[_n];
}
int main(void){
	d[1] = 1, d[2] = 2, d[3] = 4;
	int n, t;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &t);
		printf("%d\n", add(t));
	}
	// d[i] = d[i-1] + d[i-2] + d[i-3]
	// @ + @ + @ + ... + @ = n: 마지막 @에 올 수 있는 수는 1, 2, 3..! 
	return 0;
}
