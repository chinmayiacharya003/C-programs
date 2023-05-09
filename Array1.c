
#include <stdio.h>
#include<stdlib.h>

void accept(int array[10],int n)
{
    printf("Enter the elements\n");
    for(int i=0;i<n;i++)
        scanf("%d",&array[i]);
}

void display(int array[10],int n)
{
    printf("The elements are\n");
    for(int i=0;i<n;i++)
        printf("%d\t",array[i]);
    printf("\n");    
}



int main() {
    int array[10],n,ch;
    while(1)
    {
        printf("Enter 1.Insert 2.Display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the number of elements ");
                scanf("%d",&n);
                accept(array,n);
                break;
            case 2:
                display(array,n);
                break;
            default: 
                printf("EXIT\n");
                exit(0);        
        }
    }
    return 0;
}
