#include <cstdio>
#include <cstring>

int n, m, pr, pc, ans = 0, tmp_ans = 0;
char dir;
bool flag = false, result = false;
char space[500][500];
int tmp[500][500];
bool check[500][500][4];	// 동일한 칸을 같은 방향에서 들어갔는지 
int row[] = {0, 1, 0, -1};
int col[] = {-1, 0, 1, 0};
char st[] = {'L', 'D', 'R', 'U'};

bool isin(int r, int c);
void judge(int r, int c, int d);
void go(int r, int c, int d);

void show() {
	puts("");
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			printf("%2d ", tmp[i][j]);
		}
		puts("");
	}
}

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			scanf(" %c", &space[i][j]);
		}
	}
	
	scanf("%d %d", &pr, &pc);
	
	pr--; pc--;
	
	for (int i=0; i<4; i++) {
		memset(check, false, sizeof(check));
		memset(tmp, 0, sizeof(tmp));
		flag = false;
		tmp_ans = 0;
		tmp[pr][pc] = 1;
		go(pr+row[i], pc+col[i], i);
		show();
		if (flag) { dir = st[i]; result = true; continue; }
		if (ans <= tmp_ans) { ans = tmp_ans; dir = st[i]; }
	}
	
	if (result) printf("%c\nVoyager\n", dir);
	else printf("%c\n%d", dir, ans);
	
	return 0;
}

bool isin(int r, int c) {
	return (0 <= r && r < n && 0 <= c && c < m);
}

void judge(int r, int c, int d) {
	if (!isin(r, c) || space[r][c] == 'C') { 
		tmp_ans = tmp[r+row[(d+2)%4]][c+col[(d+2)%4]];
		return;
	}
		
	if (space[r][c] == '/') {
		if (d < 2) {
			tmp[r][c] = tmp[r+row[(d+2)%4]][c+col[(d+2)%4]] + 1;
			go(r+row[1-d], c+col[1-d], 1-d);
		} else {
			tmp[r][c] = tmp[r+row[(d+2)%4]][c+col[(d+2)%4]] + 1;
			go (r+row[5-d], c+col[5-d], 5-d);
		}
	} else {
		tmp[r][c] = tmp[r+row[(d+2)%4]][c+col[(d+2)%4]] + 1;
		go(r+row[3-d], c+col[3-d], 3-d);
	}
}

void go(int r, int c, int d) {
	if (check[r][c][d] == true) { flag = true; return; }
	
	while (space[r][c] == '.') {
		if (check[r][c][d] == true) { flag = true; return; }
		check[r][c][d] = true;
		tmp[r][c] = tmp[r+row[(d+2)%4]][c+col[(d+2)%4]] + 1;
		r += row[d];
		c += col[d];
	}
	
	judge(r, c, d);
}
