#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	for (int tc=1; tc<=10; tc++) {
		int box[100];
		int dump;	scanf("%d", &dump);
		for (int i=0; i<100; i++) scanf("%d", &box[i]);
		for (int i=0; i<dump; i++) {
			sort(box, box+100);
			box[99] -= 1;
			box[0] += 1;
			if (box[99] - box[0] <= 1) break;
		}
		sort(box, box+100);
		printf("#%d %d\n", tc, box[99] - box[0]);
	}
	return 0;
}
