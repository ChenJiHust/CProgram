#include <stdio.h>

void BitMoveRight(void)
{
	unsigned int DatTemp = 0x12345678;
	unsigned int tmp = 0xffffffff;
	printf("%d,%d\n",tmp,tmp<<4);
	tmp = DatTemp&0xff;
	tmp = (tmp>>4)*10+(tmp&0xf);
	printf("%d\n",tmp);
	
	return ;
}

int main()
{

	FILE *fp;
	fp = fopen("D:\\c&c++\\³ÌÐò\\testvc6.0\\test\\1.c","a");
	fflush(fp);
	fseek(fp,0,SEEK_END);
	printf("%d\n",ftell(fp));
	fprintf(fp,"sample");
	printf("%d\n",ftell(fp));
	return 1;
}sample