#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
	int stack[50];
	int top;
}s;

char post[50];

int push(int x)
{
    if(s.top==49)
    {
        printf("Stack Overflow");
        return -1;
    }
    s.top++;
    s.stack[s.top] = x;
    return 1;
}
int pop()
{
    int x;
    x=s.stack[s.top];
    s.top--;
    return x;
}

int operation(int a,int b,char op)
{
    switch(op)
    {
        case '+':return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':return a/b;
    }
}

void evaluation(char str[])
{
    int i=0;
    int a,b,res;
    char sym;
    s.top==-1;
    strrev(post);
    while(str[i]!='\0')
    {
        sym=post[i];

        if(str[i]>='0'&&str[i]<='9')
        {
            push(sym-'0');
        }
        else
        {
            a=pop();
            b=pop();
            res=operation(a,b,sym);
            push(res);
        }
        i++;
    }
    printf("%d",pop());
}

int main()
{
    printf("\nEnter Postfix expression: ");
    scanf("%s", &post);

    printf("Prefix Expression:");
    printf(strrev(post));

    printf("\nPrefix Expression Evaluation:");
    evaluation(post);

    return 0;
}
