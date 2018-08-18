#include<cstdio>

int find_set(int* _set, int _a);
void union_set(int* _set, int _a, int _b);

int main(void)
{
	int n, m, a, b, op;
	
	scanf("%d %d", &n, &m);
	
	int* set = new int[n + 1];
	
	for(int i=0;i<=n;i++)
	{
		set[i] = i;
	}
	
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d", &op, &a, &b);
		
		if(op == 0)
		{
			union_set(set, a, b);
		}
		else
		{
			if(find_set(set, a) != find_set(set, b))
			{
				printf("NO\n");
			}
			else
			{
				printf("YES\n");	
			}
		}
	}
	
	return 0;
}

int find_set(int* _set, int _a)
{
	while(_set[_a] != _a)
	{
		_a = _set[_a];
	}
	return _a;
}

void union_set(int* _set, int _a, int _b)
{
	if(find_set(_set, _a) != find_set(_set, _b))
	{
		_set[find_set(_set, _b)] = find_set(_set, _a);
	}
}
