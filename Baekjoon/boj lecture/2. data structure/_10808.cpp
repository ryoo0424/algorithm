#include<cstdio>
using namespace std;
char s[101];
int apb[26];
int main(void){
	scanf("%s", s);
	for (int i=0; s[i]; i++) apb[s[i]-'a'] += 1;
	for (int i=0; i<26; i++) printf("%d ", apb[i]);	
	return 0;
}
