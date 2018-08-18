#include<iostream>
using namespace std;
int main(void){
	int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int x, y, sum = 0;
	scanf("%d %d", &x, &y);
	for (int i = 0; i < x; i++){
		sum += month[i];
	} sum += y;
	sum = sum % 7;
	if (sum == 0) printf("SUN\n");
	else if (sum == 1) printf("MON\n");
	else if (sum == 2) printf("TUE\n");
	else if (sum == 3) printf("WED\n");
	else if (sum == 4) printf("THU\n");
	else if (sum == 5) printf("FRI\n");
	else printf("SAT\n");
	return 0;
}
