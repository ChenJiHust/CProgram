/*Sample code to read in test cases:*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define NUM 1024

int h[100][100],N,M,H,S,F;
int flag[100][100];

int onestep(int sx,int sy,int tx,int ty)

{
	int walk,swim,tran,minx;
	walk = abs(h[sx][sy] - h[tx][ty]) + F;
	swim = S;
	if( (h[sx][sy] < H) || (h[tx][ty] < H) )
	{
		if(h[sx][sy] >= H)
			tran = F + h[sx][sy] - H;
		else if(h[tx][ty] >= H)
			tran = F + h[tx][ty] - H;
		else
			tran = F;
	}
	else
		tran = 10241024;
	minx = (walk > swim)?((swim>tran)?tran:swim):((walk>tran)?tran:walk);
	return minx;
}
int step(int sx,int sy,int tx,int ty)
{
	int tmp = -2;
	int up,down,left,right;
	up=down=left=right=-1;
	if((sx==tx)&&(sy==ty))
		return 0;
	flag[sx][sy] = -1;
	if((sx>1) && !flag[sx-1][sy])
	{
		up = onestep(sx,sy,sx-1,sy) + step(sx-1,sy,tx,ty);
		tmp = up;
	}
	if((sx<N) && !flag[sx+1][sy])
	{
		down = onestep(sx,sy,sx+1,sy) + step(sx+1,sy,tx,ty);
		if((tmp>down) || (tmp == -2))
			tmp = down;
	}
	if((sy>1) && !flag[sx][sy-1])
	{
		left = onestep(sx,sy,sx,sy-1) + step(sx,sy-1,tx,ty);
		if((tmp > left) ||(tmp == -2))
			tmp = left;
	}
	if((sy<M) && !flag[sx][sy+1])
	{
		right = onestep(sx,sy,sx,sy+1) + step(sx,sy+1,tx,ty);
		if((tmp > right)||(tmp == -2))
			tmp = right;
	}
	flag[sx][sy] = 0;
	if(tmp == -2)
		tmp = 10241024;
	return tmp;
	


}

int main()
{
	FILE * pFile;
	int sx,sy,tx,ty;
	int i,j;            
	char mystring[NUM];
	char *tmp1,*tmp2;
	char sysInputFile[] = "D:\\c&c++\\³ÌÐò\\TX\\testland.txt";
	pFile = fopen(sysInputFile, "r");
	while(fgets(mystring, NUM, pFile))
	{
		sscanf(mystring,"%d%d%d%d%d",&N,&M,&H,&S,&F);
		fgets(mystring,NUM,pFile);
		sscanf(mystring,"%d%d%d%d",&sx,&sy,&tx,&ty);
		i = 1;
		while((i<=N) && fgets(mystring, NUM, pFile))
		{
			tmp1 = mystring;
			j = 1;
			while(j<=M)
			{
				tmp2 =  strchr(tmp1,' ');
				if(tmp2 != NULL)
					*tmp2='\0';
				h[i][j] = atoi(tmp1);
				tmp1 = ++tmp2;
				j++;
			}
			i++;
		}
		i = step(sx,sy,tx,ty);
		printf("%d\n",i);
		
	}
	fclose(pFile);
	return 0;
}