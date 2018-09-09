#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main() {
	
	return 0;
}
/*
node: {1, 2, 3, 4, 5, 6}
edge: {(1, 2), (1, 5), .... , (4, 6)}
----------------------------------------------------
1. adjacency-matrix vs. 2. adjacency-list 
1. 가중치가 있는 경우 가중치의 범위 조건에 따라 있는지 없는지 하나
	가중치 하나를 같이 써야 함 (O(V^2))
2. linked list를 이용해서 구현함(vector or array list) 
	-> 저장된 값이 정점이 아니라 사실상 해당 정점과의 간선 (O(E)) 
	# vector<int> a(10) = int a[10]
	# vector<int> a[10] = int a[10][] (의미상 이런 형태) 
	-> 가중치가 있는 경우 vector< pair<int,int> > a[e];
----------------------------------------------------
edge-list (간선 리스트) ?????????? 
int E[][2];
----------------------------------------------------
DFS(stack) vs. BFS(queue)
: 모든 정점을 1번씩 방문하는 것이 목표 
*/
