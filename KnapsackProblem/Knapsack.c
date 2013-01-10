#include <stdio.h>


#define N  6
#define V  10

int c[6] = {4,3,2,3,2,4};
int w[6] = {12,9,14,6,8,13};

void knapsack(){
	int f[11];
	int i,j,tmp;
	for(i = 0; i < V + 1 ; i++)
		f[i] = 0;
	for(i = 0; i < N; i++){
		for(j = V+1; j >= c[i];j--){
			tmp = f[j - c[i]] + w[i];
			if(tmp > f[j])
				f[j] = tmp;
		}
	}
	for(i = 0;i <= V; i++)
		printf("%d\t",f[i]);
}
int main(){
	knapsack();
	return 0;
}