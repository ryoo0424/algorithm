#include "turboc.h"

class position{
	private:
		int x;
		int y;
		char ch;
	
	public:
		void initRand(){
			x = random(80);
			y = random(24);
			ch = random('Z'-'A'+1)+'A';
		}
		void outPosition(){
			gotoxy(x, y);
			putch(ch);
		}
		void erasePosition(){
			gotoxy(x, y);
			putch(' ');
		}
};

int main(){
	position arPos[50];
	position *pPos;
	int i;
	
	randomize();
	for(i=0;i<sizeof(arPos)/sizeof(arPos[0]);i++){
		arPos[i].initRand();
		arPos[i].outPosition();
		delay(50);
	}
	
	delay(1000);
	pPos = arPos;
	for(i=0;i<sizeof(arPos)/sizeof(arPos[0]);i++){
		pPos->erasePosition();
		pPos++;
		delay(50);
	}
	return 0;
}
