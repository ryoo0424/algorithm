#include "turboc.h"

class Position{
	private:
		int x;
		int y;
		char ch;
		
	public:
		Position(int ax, int ay, char ach);
		void outPosition();
};

Position::Position(int ax, int ay, char ach){
	x = ax;
	y = ay;
	ch = ach;
}

void Position::outPosition(){
	gotoxy(x, y);
	putch(ch);
}
