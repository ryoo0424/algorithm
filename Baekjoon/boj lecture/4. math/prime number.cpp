#include<iostream>
using namespace std;
bool prime(int _n) {
	if (n < 2) return false;
	for (int i=2; i*i<=n; i++) if (n % i == 2) return false;
	return true;
} // �� root(n)������ �غ��� �Ǵ��� �ٽ� �� �� �����غ��� (O(root(n)) 
int main(){
	/*
	sieve of Eratosthenes
	: �������� ���� �� �߿��� ���� ���� ���� �Ҽ���
	: ���� ������ �ش� ���� ��� ����� �������� 
	*/
	int p[100]; // �Ҽ� ����
	int pn = 0; // �Ҽ��� ����
	bool c[101]; // ���������� true
	int n = 100; // 100������ �Ҽ�
	for (int i=2; i<=n; i++) {
		if (c[i] == false) {
			p[pn++] = i;
			for (int j=i*i; j<=n; j+=i) c[j] = true;
		}
	}
	// �����佺�׳׽��� ü ���� �غ� �� 
	return 0;
}

