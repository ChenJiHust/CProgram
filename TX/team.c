/*Sample code to read in test cases:*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM 1024

int main()
{
	FILE * pFile;
	int T,n;
	char mystring[NUM];
	char sysInputFile[] = "D:\\c&c++\\³ÌÐò\\TX\\testteam.txt";
	char *name;
	pFile = fopen(sysInputFile, "r");
	fgets(mystring, NUM, pFile);
	T = atoi(mystring);
	while(T--)
	{
		fgets(mystring, NUM, pFile);
		n = atoi(mystring);
		while ((n--) && fgets(mystring, NUM, pFile)) {
			if (mystring == NULL) {
				n++;
				continue;// Skip empty lines
			}
			else
			{
			}
		}
	}
	fclose(pFile);
	return 0;
}