#include "turboc.h"

struct position{
	int x;
	int y;
	char ch;
	void outPosition(); // 구조체 안에 메소드의 원형만 밝혀둠 
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
