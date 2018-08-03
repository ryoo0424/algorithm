#include<stdio.h>
#include<malloc.h>
#include<algorithm>

int main(){
	int T;
	scanf("%d", &T);
	for(int i=0;i<T;i++){
		int N;
		scanf("%d", &N);
		// malloc sticker array
		int **sticker = new int*[ROW];
		for(int i=0;i<ROW;i++){
			sticker[i] = new int[N];
		}
		// get the score of each sticker
		for(int i=0;i<ROW;i++){
			for(int j=0;j<N;j++){
				scanf("%d", &sticker[i][j]);
			}
		}
		/*
		available action in each column
		1. do nothing: independent to prior step
			> D(1,n) = max(D(1,n-1), D(2,n-1), D(3,n-1))
		2. get upper side sticker: only when left upper one is alive
			> D(2,n) = max(D(1,n-1), D(3,n-1)) + stikcer(1,n)
		3. get lower side sticker: only when left lower one is alive
			> D(3,n) = max(D(1,n-1), D(2,n-1)) + sticker(2,n)
			
		http://private-space.tistory.com/26
		*/		
		// delete sticker array
		for(int i=0;i<ROW;i++) delete [] sticker[i];
		delete [] sticker;
	}		
	return 0;
}
