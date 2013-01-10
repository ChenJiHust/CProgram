
/*

题目描述：
  把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。
  习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

输入：
  输入包括一个整数N(1<=N<=1500)。

输出：
  可能有多组测试数据，对于每组数据，
  输出第N个丑数。

样例输入：
  3

样例输出：
  3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int * arr = NULL;
	int N;
	scanf("%d",&N);
	arr = (int *)malloc(sizeof(int)*3000);
	memset(arr,0,sizeof(int)*3000);
	arr[1]=1;
}