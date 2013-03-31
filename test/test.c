#include <stdio.h>
#include <math.h>

/*
����һ��������N��д�´�1��ʼ����N�����������У�����1�ĸ�����
���磺��N=12ʱ������1,10,11,12���ܹ�����1�Ĵ���Ϊ5
*/




//ͳ����num�г��ֵ�1�ĸ���
int count(int num)
{
	int sum = 0;
	int tmp;
	while(num)
	{
		tmp = num%10;
		num /=10;
		if(tmp == 1)
			sum++;
	}
	return sum;
}

int process1(int n)
{
	int sum = 0;
	int i  =0;
	for(;i<=n;i++)
		sum+= count(i);
	return sum;
}


//�����֮��P135
int process2(int num)
{
	int sum = 0;
	int tmp,n = num;
	int k = 1;
	while(n)
	{
		tmp = n%10;
		n /=10;		
		sum += n*k;
		if(tmp>1)
			sum += k;
		if(tmp == 1)
			sum += num%k+1;
		k*=10;
	}
	return sum;
}


int main()
{
	int n,sum1,sum2;
	for(n = 1;n<20000;n++)
	{
		sum1 = process1(n);
		sum2 = process2(n);
		if(sum1 != sum2)
			printf("%d  %d  %d\n",n,sum1,sum2);
	}
	return 0;
}