#include "turboc.h"

struct position{
	int x;
	int y;
	char ch;
	void outPosition(); // ����ü �ȿ� �޼ҵ��� ������ ������ 
};

void position::outPosition(){ // 
	gotoxy(x,y);
	putch(ch);
}

int main(){
	position here;
	here.x = 30;
	here.y = 10;
	here.ch = 'A';
	here.outPosition();	
	
	return 0;
}
