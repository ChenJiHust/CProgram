#include <stdio.h>
#include <math.h>

int exponentiation(int a,int n)
{
	int z = 1;
	while(n > 0)
	{
		if(n % 2 == 1)
			z *= a;
		a *=a;
		n /=2;
	}
	return z;
}

int main()
{
	int i =0;
	for(i = 0;i < 11;i++)
		printf("%d\n",exponentiation(2,i));
	return 0;
}