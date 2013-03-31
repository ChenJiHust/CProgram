#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 1024

int main()
{
	FILE * pFile;
	char mystring[NUM];
	char *str;
	int num[NUM];
	int cases;
	int count,i;
	char sysInputFile[] = "D:\\c&c++\\³ÌÐò\\testvc6.0\\CProgram\\TX\\zp.txt";
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
				sscanf(mystring,"%d",&count);
				fgets(mystring,NUM,pFile);
				str = mystring;
				for(i = 0;i<count;i++)
				{
					sscanf(str,"%d",&num[i]);
					str = strstr(str," ")+1;
				}
				for(i = 0;i<count;i++)
					printf("%d\t",num[i]);
				printf("\n");
				break;
				// Do something with the line
			}
		}
	}
	fclose(pFile);
    return 0;
}