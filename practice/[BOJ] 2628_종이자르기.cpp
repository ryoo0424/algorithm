#include <iostream>
using namespace std;
int main() {
	bool w_list[101] = {false};
	bool h_list[101] = {false};
	int width, height;	cin >> width >> height;
	int n;	cin >> n;
	w_list[0] = w_list[width] = true;
	h_list[0] = h_list[height] = true;
	int w_cnt = 1, h_cnt = 1;
	for (int i=0; i<n; i++) {
		int dir, coord;	cin >> dir >> coord;
		if (dir == 1) {
			w_list[coord] = true;
			w_cnt += 1;
		} else {
			h_list[coord] = true;
			h_cnt += 1;
		}
	}
	int ans = 0, w_s = 0, w_e = 0;
	for (int i=0; i<w_cnt; i++) {
		w_s = w_e++;
		while (!w_list[w_e]) w_e += 1;
		int h_s = 0, h_e = 0;
		for (int j=0; j<h_cnt; j++) {
			h_s = h_e++;
			while (!h_list[h_e]) h_e += 1;
			if (ans < (w_e - w_s) * (h_e - h_s)) ans = (w_e - w_s) * (h_e - h_s);
		}
	}
	cout << ans << '\n';
	return 0;
}
