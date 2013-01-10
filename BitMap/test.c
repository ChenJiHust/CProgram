#include <stdio.h>
#include <string.h>
#include "bitMap.h"

int main()
{
	int a[5] = {1,8,4,3,9};
	int *bitmap;
	int i,j=0;
	bitmap = (int*)malloc(sizeof(int)*2);
	memset(bitmap,0,sizeof(int)*2);
	for(i = 0;i<5;i++)
		set(bitmap,a[i]);
	while(i){
		if(test(bitmap,j))
		{
			i--;
			printf("%d\n",j);
		}
		j++;
	}
	return 0;
}