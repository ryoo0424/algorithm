#include "turboc.h"

struct B{
	private:
		int a;
		double b;
		char ch;
		void init();
	public:
		int x;
		int y;
		void func(int i);
	protected:
		float k;			
};

int main(){
	B Kim;
	Kim.a = 1;
	Kim.x = 10;
	Kim.func(3);
	Kim.init();	
	
	return 0;
}
