/*用栈实现括号匹配*/
/*
样例输入 Copy
{}{}(([]))
样例输出 Copy
1
*/
#include<stdio.h>
#include<stdlib.h>
typedef char ElementType;
typedef struct
{
	ElementType* array;
	int top;	 		
	int data;  		
} SeqStack;

char a[] = { '{','[','(','+' };

int f(char x)
{
	if (x == '}') return 0;
	if (x == ']') return 1;
	if (x == ')') return 2;
	return 3;
}


int main()
{
	SeqStack* s;
	s = (SeqStack*)malloc(sizeof(SeqStack));
	s->array = (ElementType*)malloc(1005 * sizeof(ElementType));
	s->data = 1005;
	s->top = -1;
	char x, t[1000];
	scanf("%s", t);
	for (int i = 0; t[i] != '\0'; i++) {
		x = t[i];
		if (s->top == -1 || s->array[s->top] != a[f(x)]) {
			s->top++;
			s->array[s->top] = x;
		}
		else {
			s->top--;
		}
	}
	if (s->top > -1)
		printf("0\n");
	else
		printf("1\n");
	return 0;
}

