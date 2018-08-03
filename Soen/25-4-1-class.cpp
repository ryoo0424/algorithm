#include "turboc.h"

using namespace std;

class position{
	public:
		int x;
		int y;
		char ch;
		void outPosition();
};

void position::outPosition(){
	gotoxy(x, y);
	putch(ch);
}

int main(){
	position ps;
	cin >> ps.x >> ps.y >> ps.ch;
	ps.outPosition();
	
	return 0;
}
