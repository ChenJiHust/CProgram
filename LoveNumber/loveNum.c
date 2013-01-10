#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 ������(Amicable Pair)���ֳ��׺������Ѱ�����ָ�����������У��˴˵�ȫ��Լ��֮�ͣ�������⣩����һ����ȡ�
 ����220��284��
 220��ȫ��Լ��(��������)����ǣ�1+2+4+5+10+11+20+22+44+55+110=284
 284��ȫ��Լ��(����284����)��ӵĺ��ǣ�1+2+4+71+142=220
 ���仰˵���׺����ֿ���˵���������������У�һ����ȫ��Լ��֮������һ����ȫ��Լ��֮����ȡ�
 220��ȫ��Լ��֮���ǣ�1+2+4+5+10+11+20+22+44+55+110+220 = 284+220 = 504
 284��ȫ��Լ��֮���ǣ�1+2+4+71+142+284 = 220+284 = 504
 */


/*
int process(int k)
{
	int sum = 1;
	int start = 2,end ,tmp;
	end = (int)sqrt(k)+1;
	while((start < end))
	{
		if(k%start == 0)
		{
			sum+= start;
			tmp = k/start;
			if(tmp != start)
				sum+=tmp;
		}
		start++;
	}
	return sum;
}
void find(int k)
{
	int i=2;
	int tmp;
	int count=0;
	for(;i<k;i++)
	{
		tmp = process(i);
		if((tmp < i) && (i == process(tmp)))
		{
			printf("LoveNumber %d----%d\n",i,tmp);
			count++;
		}
	}
	printf("count%d\n",count);
	return;
}
*/


#define MAX 5000000
int a[MAX+10];
void find2()
{	
	int i,j,count=0;
	for(i=0;i<MAX;i++)
		a[i]=1;
	for(i=2;i<MAX;i++)
	{
		for(j = i*2;j<MAX;j+=i)
			a[j]+=i;
	}
	for(i = 1;i<MAX;i++)
		if((i>a[i]) && (a[a[i]] == i))
		{
			printf("LoveNumber %d----%d\n",i,a[i]);
			count++;
		}
	printf("count  =  %d\n",count);
	return;
}


int main()
{
	find2();
	//printf("%d\n%d\n",process(220),process(284));
	return 0;
}