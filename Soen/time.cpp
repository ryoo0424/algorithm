#include "time.h"
#include <iostream>

using namespace std;

void Time::SetTime(int h, int m, int s){
	hour = h;
	min = m;
	sec = s;
}
void Time::OutTime(){
	cout << hour << ":" << min << ":" << sec << endl;
}

