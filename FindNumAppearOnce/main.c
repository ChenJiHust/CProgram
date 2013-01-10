#include <stdio.h>

/*
一个整型数组里除了两个数字之外，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。
要求时间复杂度是O(n)，空间复杂度是O(1)。

异或运算的性质：任何一个数字异或它自己都等于0。
也就是说，如果我们从头到尾依次异或数组中的每一个数字，
那么最终的结果刚好是那个只出现一次的数字，因为那些出现两次的数字全部在异或中抵消掉了。

有两个数字都只出现了一次，所以要分成两组。

还是根据异或运算的性质分组。找到某个位为1。
*/
void find(int arr[],int len)
{
	int i,tmp = 0;
	int num1=0,num2=0;
	int flag = 1;
	for(i = 0;i<len;i++)
	{
		tmp = tmp ^ arr[i];
	}

	while((tmp%2)==0)
	{
		flag*=2;
		tmp/=2;
	}
	for(i = 0;i<len;i++)
	{
		if(arr[i]&flag)
			num1 ^= arr[i];
		else
			num2 ^= arr[i];
	}
	printf("%d\n%d\n",num1,num2);
}

int main()
{
	int a[] = {1,2,2,1,7,5,5,8,10,8};
	find(a,(int)sizeof(a)/sizeof(a[0]));
}