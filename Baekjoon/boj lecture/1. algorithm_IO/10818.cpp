#include<iostream>
using namespace std;
int main(void){
	int n, min, max, tmp;
	scanf("%d", &n);
	scanf("%d", &tmp);
	min = max = tmp;
	n--;
	while (n--) {
		scanf("%d", &tmp);
		if (tmp >= max) max = tmp;
		if (tmp <= min) min = tmp;
	}
	printf("%d %d\n", min, max);
	return 0;
}
