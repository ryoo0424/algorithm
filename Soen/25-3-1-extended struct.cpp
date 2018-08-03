#include "turboc.h"
// Pos1
struct Position{
	int x;
	int y;
	char ch;
};

void OutPosition(Position Pos){
	gotoxy(Pos.x, Pos.y);
	putch(Pos.ch);
}

// Pos2
struct Pos2{
	int x;
	int y;
	char ch;
	void OutPosition(){
		gotoxy(x,y);
		putch(ch);
	}
};

int main(){
	// Pos1
	/*
	Position Here;
	Here.x = 30;
	Here.y = 10;
	Here.ch = 'A';
	OutPosition(Here);
	*/
	
	// Pos2
	Pos2 Here2;
	Here2.x = 30;
	Here2.y = 10;
	Here2.ch = 'A';
	Here2.OutPosition();
	
	return 0;
}

