/*Sample code to read in test cases:*/
#include <stdio.h>
#include <string.h>
#define NUM 1024

int x,y,n,a,b;
char stack[10241];
char lol[16] = {'a','b','c','d','e','f','g','h',  'i','j','k','l','m','n','o','p'};     
int sep[16];                                
int ge[100];
char result[100];
int sum;
int bp = -1;
int flag[16];
int left;

void push(char ch)
{
	stack[++bp] = ch;
	return;
}
char pop()
{
	char ch;
	ch = stack[bp--];
	return ch;
}

int check()
{
	int i;
	char *ptr;
	result[n] = '\0';
	for(i=0;i<x+y;i++)
	{
		ptr = strchr(result,lol[i]);
		if(!ptr)
			return 0;
	}
	return 1;
}

int count()
{
	int i,j,tmp;
	sum=0;
	for(i=0;i<x+y;i++)
		push(lol[i]);
	for(i=0;i<16;i++)
	{
		flag[i] = 0;
	}
	ge[0]=x+y;
	j=0;
	left = 0;
	while(bp != -1)
	{
		if(!ge[j])
		{
			j--;
			if(flag[result[j]-'a'] > 0)
			{
				if(--flag[result[j]-'a'] == 0)
					left--;
			}
			
			continue;
		}
		ge[j]--;
		result[j] = pop();
		tmp = result[j]-'a';
		if(flag[tmp]++ == 0)
			left++;
		j++;
		if((left + n - j < x + y) || (j == n))
		{
			if(left == x+y)
				sum++;
			j--;
			if(flag[tmp] > 0)
			{
				if(--flag[tmp] == 0)
					left--;
			}
			continue;
		}		
		sep[tmp] = (tmp >= x)?b:a;
		for(i=0;i<x+y;i++)
		{
			if(i == tmp)
				continue;
			if(sep[i] < 2)
			{
				push(lol[i]);
				ge[j]++;
				if(sep[i] == 1)
					sep[i]--;
			}
			else
			{
				sep[i]--;
			}
		}
		

	}
	printf("%d\n",sum);

}

int main()
{
	FILE * pFile;
	char mystring[NUM];
	int cases;
	char sysInputFile[] = "D:\\c&c++\\³ÌÐò\\TX\\testLOL.txt";
	pFile = fopen(sysInputFile, "r");
	fgets(mystring,NUM,pFile);
	sscanf(mystring,"%d",&cases);
	while(cases--)
	{
		while (fgets(mystring, NUM, pFile))
		{
			if (mystring == NULL) {
				continue;// Skip empty lines
			}
			else
			{
				sscanf(mystring,"%d%d%d%d%d",&n,&x,&y,&a,&b);
				count();
				break;
				// Do something with the line
			}
		}
	}
	fclose(pFile);
    return 0;
}