/*
There are some glasses with equal capacity as 1 litre. The glasses are kept as follows:

    			   1
		         2   3
		      4    5    6
		    7    8    9   10

You can put water to only top glass. If you put more than 1 litre water to 1st glass, 
water overflows and fills equally in both 2nd and 3rd glasses. 
Glass 5 will get water from both 2nd glass and 3rd glass and so on.
If you have X litre of water and you put that water in top glass, 
how much water will be contained by jth glass in ith row?

Example. If you will put 2 litre on top.
1st – 1 litre
2nd – 1/2 litre
3rd – 1/2 litre
*/

#include <stdio.h>

float overflows(int i,int j,int x)             //求溢出的水量
{
	float tmp = 0;
	if(j == 1)
		return (x >= 1 )?(float)(x-1):0;
	if(j == (i*(i-1)/2+1))
	{
		tmp = overflows(i-1,j-i+1,x)/2;
	}
	else if(j == (i*(i-1)/2+i))
	{
		tmp = overflows(i-1,j-i,x)/2;
	}
	else
	{
		tmp = overflows(i-1,j-i,x)/2 + overflows(i-1,j-i+1,x)/2;
	}
	return (tmp > j)?(tmp-j):0;
}

float findwater(int i,int j,int x)            //根据上面溢出来的水量计算
{
	float tmp = 0;
	if(j == (i*(i-1)/2+1))
	{
		tmp = overflows(i-1,j-i+1,x)/2;
	}
	else if(j == (i*(i-1)/2+i))
	{
		tmp = overflows(i-1,j-i,x)/2;
	}
	else
	{
		tmp = overflows(i-1,j-i,x)/2 + overflows(i-1,j-i+1,x)/2;
	}
	return (tmp > j)?j:tmp;
}

int main()
{
	printf("Amount of water in jth glass of ith row is: %f\n",findwater(3, 4, 8));
	return 0;
}