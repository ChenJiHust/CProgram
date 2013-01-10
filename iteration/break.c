#include <stdio.h>

int main()
{
	int i = 0;
chenji:
	for(;i<3;i++)
	{
		if(i == 1)
			continue;
		printf("i = %d\n",i);
		
	}
	return 0;
}