#include<cstdio>

long long fibo(int _n);

int main(void)
{
	int input;
	scanf("%d", &input);
	printf("%lld", fibo(input));
	return 0;
}

long long fibo(int _n)
{
	long long curr = 0, next = 1;
	
	if(_n == 0 || _n == 1)
		return curr;
	else if (_n == 2) 
		return next;
	else
	{
		for(int i=3;i<=_n + 1;i++)
		{
			next = curr + next;
			curr = next - curr;
		}
		return next;
	}
}
