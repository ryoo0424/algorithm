#include "position.h"

int main(){
	Position here(30, 10, 'A');
	// Position here = Position(30, 10, 'A');
	here.outPosition();
	
	/*
	������ �����ε��� �� ��
		Position(int ax, int ay, char ach='S');
	�̷� ������� �ϸ� ach�� ����Ʈ ������ S�� �ִ� ��! 
	*/
	return 0;
}
