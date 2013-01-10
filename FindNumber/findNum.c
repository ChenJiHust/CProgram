#include <stdio.h>

#define MAX 100
int stack[MAX];
int sp = -1;

int pop(){
	return stack[sp--];
}
void push(int c){
	stack[++sp] = c;
	return;
}

void printall()
{
	int tmp = 0;
	while(tmp <= sp)
		printf("%d\t",stack[tmp++]);
	return;

}

/*
从1，2，3，…，n，数列中选出k个数，使其和为sum。

  使用递归，栈用来保存当前选择的数。
  对于n，如果选择，那么接下来的问题就是从1，2，3，…，n-1数列中选择k-1个数，其和为sum-n；
  如果不选择，则表示从1，2，3，…，n-1数列中选择k个数，其和为sum。
这即是背包问题


  其次需要注意递归出口。

  假如不限定个数k。那么消去参数k即可，输出时无需判断 k==1，
     此时需要注意的是 满足条件输出时 不一定是递归出口，必须删掉return语句，继续向下递归。
*/
void find(int sum ,int n,int k)
{
	if((n<=0) || (sum<=0))
		return ;
	if((sum == n) && (k==1))
	{
		printall();
		printf("%d\n",n);
		return;
	}
	push(n);
	find(sum-n,n-1,k-1);
	pop();
	find(sum,n-1,k);
	return;
}

int main()
{
	find(9,5,3);
	return 1;
}