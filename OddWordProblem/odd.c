#include <stdio.h>
#include <ctype.h>

#define MAX 100
char stack[MAX];
int sp = -1;

char pop(){
	sp--;
	return stack[sp + 1];
}
void push(char c){
	stack[++sp] = c;
	return;
}

void popall(){
	while(sp != -1){
		putchar(pop());
	}
	return ;
}

int main()
{
	int flag = 0;
	int c;
	do{
		c = getchar();
		if(!flag){
			putchar(c);
			if(!isalpha(c))
				flag = 1;
		}
		else{
			if(isalpha(c))
				push(c);
			else{
				popall();
				putchar(c);
				flag = 0;
			}			
		}
	}while(c != '.');

	return 0;
}