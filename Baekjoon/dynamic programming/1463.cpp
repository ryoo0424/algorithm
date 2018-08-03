#include<stdio.h>
#include<string.h>

void find(int _arr[], int _input);
int min(int _a, int _b);

#define MAX 1000001
int arr[MAX];
	
int main(void){
	int input;	
	
	scanf("%d", &input);
	memset(arr, 0, sizeof(int)*(input+1));
	find(arr, input);
	printf("%d", arr[input]);	
	 	
	return 0;
}
void find(int _arr[], int _input){
	_arr[1] = 0;
	
	for(int i=2; i<=_input; i++){
		_arr[i] = _arr[i-1] + 1;
		if(i%2 == 0){
			_arr[i] = min(_arr[i], _arr[i/2] + 1);	
		}
		if(i%3 == 0){
			_arr[i] = min(_arr[i], _arr[i/3] + 1);
		}
	}
}
int min(int _a, int _b){
	if(_a < _b) return _a;
	else return _b;
}
