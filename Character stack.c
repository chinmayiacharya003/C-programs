#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20
void push(char S[max],int *top,char let)
{
    if(*top==max)
    {
        printf("Overflow\n");
        return;
    }
    (*top)++;
    S[*top]=let;
}
void pop(char S[max],int *top)
{
    
    if(*top==-1)
    {
        printf("Underflow\n");
        return;
    }
        printf("%c is popped\n",S[*top]);
    
}
void display(char S[max],int top)
{
    if(top==-1)
    {
        printf("No elements\n");
        return;
    }
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%c\t",S[i]);
    }
    printf("\n");
}


   
   
    
int main()
{
    char S[max],let,d,str[20];
    int top=-1,ch;
    while(1)
    {
        printf("Enter 1.Push 2.Pop 3.Display \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the element\n");
                scanf("%c%c",&d,&let);
                push(S,&top,let);
                break;
            case 2:
                pop(S,&top);
                break;
            case 3:
                display(S,top);
                break;
            
            default:
                printf("EXIT\n");
                exit(0);            
        }
    }
}