#include <stdio.h>
#include <stdlib.h>

/*
You have a robot in a grid, it can move in forward direction and can change 
its facing towards north, south, east n west and you are given a command sequence. 
So what will be the final position of the robot

Example
Grid(100*500)
Robot Position – (5,3)
Sequence —      {N,S,M,M,E,W,E,S,M,S,M}    North, East, West, South, Move forward
*/

int main()
{
	int N=0,M=0;  //网格大小
	int x=0,y=0;  //初始位置
	char towards,ch;
	scanf("%d%d",&N,&M);
	scanf("%d%d",&x,&y);
	while((ch = getchar()) != 'T')
	{
		switch(ch){
		case 'N':
			towards = 'N';
			break;
		case 'S':
			towards = 'S';
			break;
		case 'E':
			towards = 'E';
			break;
		case 'W':
			towards = 'W';
			break;
		case 'M':
			if(towards == 'N')
				y = (y++)%(M+1);
			else if(towards == 'S')
			{	
				y--;
				if(y<0)
					y=M;
			}
			else if(towards == 'E')
				x = (x++)%(N+1);
			else
			{
				x--;
				if(x<0)
					x=N;
			}
			break;
		}

	}
	printf("x=%d,y=%d\n",x,y);

}