#include<iostream>
using namespace std;
int main(){
	
	return 0;
}
/*
뺄셈의 경우 먼저 mod 연산을 한 결과가 음수가 나올 수 있기 때문에
	(A-B) % M = ((A % M) - (B % M) + M) % M
과 같이 해야 함 
------------------------------------------------------------------
나누기에도 성립하지 않기 때문에 modular inverse, 즉 역원을 구해야 함
*/
