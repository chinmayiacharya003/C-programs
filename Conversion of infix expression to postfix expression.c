#include<stdio.h>
#include<stdlib.h>

int G(char op)
{
    switch(op)
    {
        case '+': case '-': return 1;
        case '*': case '/': case '%': return 3;
        case '^': case '$': return 6;
        case '(': return 9;
        case ')': return 0;
        default: return 7;
    }
}
int F(char op)
{
    switch(op)
    {
        case '+': case '-': return 2;
        case '*': case '/': case '%': return 4;
        case '^': case '$': return 5;
        case '(': return 0;
        case '#': return -1;
        default: return 8;
    }
}
void push(char S[10],int * top,char c)
{
    (*top)++;
    S[*top]=c;
}
char pop(char S[10],int *top)
{
    char a=S[*top];
    (*top)--;
    return a;
}
void convert(char infix[20],char postfix[20])
{
    char S[10];
    int top=-1,j=0;
    push(S,&top,'#');
    for(int i=0;infix[i]!='\0';i++)
    {
        while(F(S[top])>G(infix[i]))
        {
            postfix[j]=pop(S,&top);
            j++;
        }
        if(F(S[top])!=G(infix[i]))
            push(S,&top,infix[i]);
        else
            pop(S,&top);  
    }
    while(top!=0)
    {
        postfix[j]=pop(S,&top);
        j++;
    }
    postfix[j]='\0';
    printf("Postfix expression: ");
    for(int i=0;postfix[i]!='\0';i++)
        printf("%c ",postfix[i]);
    printf("\n");    
}
int main()
{
    char infix[20],postfix[20];
    printf("Enter the infix expression ");
    scanf("%s",infix);
    convert(infix,postfix);
    return 0;
}