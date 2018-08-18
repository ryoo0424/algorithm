#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
int main(void){
	stack<char> left, right;
	char command;
	int n;
	char s[600001];
	scanf("%s %d", &s, &n);
	int len = strlen(s);
	for (int i=0; i<len; i++) left.push(s[i]);
	while (n--) {
		scanf(" %c", &command);
		if (command == 'P') {
			char input;
			scanf(" %c", &input);
			left.push(input);	
		}
		else if (command == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (command == 'D') {
			if (!right.empty()) { //이걸 right.size()로 하는 경우 에러가 남 
				left.push(right.top());
				right.pop();
			}
		}
		else {
			if (!left.empty()) {
				left.pop();
			}
		}
	}
	while (left.size()) {
		right.push(left.top());
		left.pop();
	}
	while (right.size()) {
		printf("%c", right.top());
		right.pop();
	}
	
	return 0;
}
