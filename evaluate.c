#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void push(int S[10],int *top,int elem)
{
    (*top)++;
    S[*top]=elem;
}
int pop(int S[10],int *top)
{
    int a=S[*top];
    (*top)--;
    return a;
}
int calculate (int a,int b, char o)
{
    switch(o)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        case '%': return a%b;
        case '^': return pow(a,b);
    }
}
void evaluate(char postfix[10])
{
    int S[10];
    int top=-1,opnd1=0,opnd2=0,res=0,fin=0;
    for(int i=0;postfix[i]!='\0';i++)
    {
        if(isdigit(postfix[i]))
        {
            push(S,&top,postfix[i]-'0');
        }
        else
        {
            opnd2=pop(S,&top);
            opnd1=pop(S,&top);
            res=calculate(opnd1,opnd2,postfix[i]);
            push(S,&top,res);
        }    
    }
    fin=pop(S,&top);
    printf("Result = %d",fin);    
}
int main()
{
    char postfix[20];
    printf("Enter the postfix expression\n");
    scanf("%s",postfix);
    evaluate(postfix);
    return 0;
}