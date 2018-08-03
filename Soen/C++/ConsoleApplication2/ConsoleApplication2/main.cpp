#include <iostream>
#include "time.h"

int main() {
	Time now;
	now.SetTime(12, 30, 40);
	now.OutTime();
	
	return 0;
}