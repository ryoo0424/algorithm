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
1. ����ġ�� �ִ� ��� ����ġ�� ���� ���ǿ� ���� �ִ��� ������ �ϳ�
	����ġ �ϳ��� ���� ��� �� (O(V^2))
2. linked list�� �̿��ؼ� ������(vector or array list) 
	-> ����� ���� ������ �ƴ϶� ��ǻ� �ش� �������� ���� (O(E)) 
	# vector<int> a(10) = int a[10]
	# vector<int> a[10] = int a[10][] (�ǹ̻� �̷� ����) 
	-> ����ġ�� �ִ� ��� vector< pair<int,int> > a[e];
----------------------------------------------------
edge-list (���� ����Ʈ) ?????????? 
int E[][2];
----------------------------------------------------
DFS(stack) vs. BFS(queue)
: ��� ������ 1���� �湮�ϴ� ���� ��ǥ 
*/
