/*Sample code to read in test cases:*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM 1024

int main()
{
	FILE * pFile;
	int i,T;
	int n,m,bp,now;
	int data[501],log[10000];
	char mystring[NUM];
	char sysInputFile[] = "D:\\c&c++\\³ÌÐò\\TX\\testmusic.txt";
	for(i = 0;i <= 500;i++)
		data[i]= i;
	memset(log,0,10000*sizeof(int));
	pFile = fopen(sysInputFile, "r");
	fgets(mystring, NUM, pFile);
	T = atoi(mystring);
	while(T--)
	{
		fgets(mystring, NUM, pFile);
		sscanf(mystring,"%d%d",&n,&m);
		bp=0;
		log[bp]=1;
		now =1;
		while ((m--) && fgets(mystring, NUM, pFile)) {
			if (mystring == NULL) {
				m++;
				continue;// Skip empty lines
			}
			else
			{
				if(*mystring == 'N')        //NEXT
				{
					if(now < n)
						now++;
					if((bp == -1)||(log[bp] != now))
						log[++bp] = now;
				}
				else if(mystring[1] == 'L') //PLAY
				{
					sscanf(mystring+5,"%d",&now);
					if((bp == -1)||(log[bp] != now))
						log[++bp] = now;
				}
				else                        //PRE
				{
					if((bp == -1)||(bp == 0))
					{
						bp = 0;
						log[bp] = 1;
						now = 1;
					}
					else
						now = log[--bp];						
				}
				printf("%d\n",now);
			// Do something with the line
			}
		}
	}
	fclose(pFile);
	return 0;
}