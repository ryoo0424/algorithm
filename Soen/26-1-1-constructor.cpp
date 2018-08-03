#include "position.h"

int main(){
	Position here(30, 10, 'A');
	// Position here = Position(30, 10, 'A');
	here.outPosition();
	
	/*
	생성자 오버로딩을 할 때
		Position(int ax, int ay, char ach='S');
	이런 방식으로 하면 ach의 디폴트 값으로 S를 주는 것! 
	*/
	return 0;
}
