/*Sample code to read in test cases:*/
#include <stdio.h>
#include <string.h>
#define NUM 1024
int test(char * c,int index)
{
	switch(index){
	case 0:
		{
			if((*c)&1)
				return 0;
			else
			{
				*c = (*c)|1;
				return 1;
			}
			break;
		}
	case 1:
		{
			if((*c)&2)
				return 0;
			else
			{
				*c = (*c)|2;
				return 1;
			}
			break;
		}
	case 2:
		{
			if((*c)&4)
				return 0;
			else
			{
				*c = (*c)|4;
				return 1;
			}
			break;
		}
	case 3:
		{
			if((*c)&8)
				return 0;
			else
			{
				*c = (*c)|8;
				return 1;
			}
			break;
		}
		case 4:
		{
			if((*c)&16)
				return 0;
			else
			{
				*c = (*c)|16;
				return 1;
			}
			break;
		}
		case 5:
		{
			if((*c)&32)
				return 0;
			else
			{
				*c = (*c)|32;
				return 1;
			}
			break;
		}
		case 6:
		{
			if((*c)&64)
				return 0;
			else
			{
				*c = (*c)|64;
				return 1;
			}
			break;
		}
		case 7:
		{
			if((*c)&128)
				return 0;
			else
			{
				*c = (*c)|128;
				return 1;
			}
			break;
		}
	}
}
int main()
{
	FILE * pFile;
	char mystring[NUM];
	int n,m,a,b,tmp,index;
	char flag[62500];
	char sysInputFile[] = "D:\\c&c++\\³ÌÐò\\TX\\test.txt";
	memset(flag,0,62500);
	pFile = fopen(sysInputFile, "r");
	fgets(mystring, NUM, pFile);
	sscanf(mystring,"%d%d",&n,&m);
	while ((m--)&&fgets(mystring, NUM, pFile)) {
		if (mystring == NULL) {
            continue;// Skip empty lines
        }
        else
		{
			sscanf(mystring,"%d%d",&a,&b);
			if((a == b)||(a>n)||(b>n))
			{
				printf("No\n");
				fclose(pFile);
				return 0;
			}
			if(a>b)
			{
				tmp = a;
				a = b;
				b = tmp;
			}
			// Do something with the line
			tmp = (b - a + 1) + (a - 1)*(2*n - a + 2)/2;
			index = tmp%8;
			tmp = tmp/8;
			if(!test(&flag[tmp],index))
			{
				printf("No\n");
				fclose(pFile);
				return 0;
			}
		}

	}
	printf("Yes\n");
	fclose(pFile);
    return 0;
}