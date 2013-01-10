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
��1��2��3������n��������ѡ��k������ʹ���Ϊsum��

  ʹ�õݹ飬ջ�������浱ǰѡ�������
  ����n�����ѡ����ô��������������Ǵ�1��2��3������n-1������ѡ��k-1���������Ϊsum-n��
  �����ѡ�����ʾ��1��2��3������n-1������ѡ��k���������Ϊsum��
�⼴�Ǳ�������


  �����Ҫע��ݹ���ڡ�

  ���粻�޶�����k����ô��ȥ����k���ɣ����ʱ�����ж� k==1��
     ��ʱ��Ҫע����� �����������ʱ ��һ���ǵݹ���ڣ�����ɾ��return��䣬�������µݹ顣
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