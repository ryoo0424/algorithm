#include "turboc.h"

using namespace std;

class Time{
	private:
		int hour, min, sec;
	public:
		void setTime(int h, int m, int s){
			hour = h;
			min = m;
			sec = s;
		}
		void outTime(){
			cout << "현재 시간은 " << hour << ":" << min << ":" << sec << " 입니다." << endl;
		}
	};

class Length{
private:

     double mili;

 
public:

     void SetMili(double m) { mili=m; }

     double GetMili() { return mili; }

     void OutMili() { printf("길이 = %fmili\n",GetMili()); }

     void SetInch(double i) { mili=i*25.4; }

     double GetInch() { return mili/25.4; }

     void OutInch() { printf("길이 = %finch\n",GetInch()); }

};

int main(){
	Time Now;
	
	Now.setTime(12, 30, 40);
	Now.outTime();
	
	 Length m;

 

     m.SetInch(3);

     m.OutMili();
	return 0;
}
