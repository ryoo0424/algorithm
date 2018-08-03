#include<stdio.h>

int main(void){
	int arr[11], t, n;
	
	scanf("%d", &t);
	
	arr[0] = 0, arr[1] = 1, arr[2] = 2, arr[3] = 4;	
	for(int j=0;j<t;j++)
	{	
		scanf("%d", &n);
		for(int i=4;i<=10;i++){
			arr[i] = arr[i-3] + arr[i-2] + arr[i-1];
		}
		printf("%d\n", arr[n]);
	}
	return 0;
}
