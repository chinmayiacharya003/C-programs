#include <stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node * link;
};
typedef struct node * NODE;

struct node * getnode()
{
    struct node * temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("No memory locations available\n");
        exit(1);
    }
    return temp;
}

NODE insert_front(NODE first,int elem)
{
     printf("Inserting front\n");
    NODE temp;
    temp=getnode();
    temp->info=elem;
    temp->link=first;
    return temp;
}

NODE insert_rear(NODE first,int elem)
{
     printf("Inserting rear\n");
    NODE temp,cur,prev;
    temp=getnode();
    temp->info=elem;
    temp->link=NULL;
    //printf("%d\n",temp->info);
    if(first==NULL)
    {
        return temp;
    }
    
   
    prev=NULL;
    cur=first;
    while(cur!=NULL)
    {
        prev=cur;
        cur=cur->link;
        
    }
    prev->link=temp;
    return first;
}

NODE delete_front(NODE first)
{
     printf("Deleting front\n");
    if(first==NULL)
    {
        printf("No elements\n");
        return first;
    }
    NODE temp;
    printf("%d is deleted\n",first->info);
    temp=first->link;
    free(first);
    return temp;
}

NODE delete_rear(NODE first)
{
    printf("Deleting rear\n");
    if(first==NULL)
    {
        printf("No elements\n");
        return NULL;
    }
    if(first->link==NULL)
    {
        printf("%d is deleted\n",first->info);
        free(first);
        return NULL;
    }
    NODE cur,prev;
    cur=first;
    prev=NULL;
    while(cur->link!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    printf("%d is deleted\n",cur->info);
    free(cur);
    prev->link=NULL;
    return first;
}

void display(NODE first)
{
    
    if(first==NULL)
    {
        printf("No elements\n");
        return;
    }
    printf("Displaying elements\n");
    NODE cur;
    cur=first;
    while(cur!=NULL)
    {
        printf("%d\t",cur->info);
        cur=cur->link;
    }printf("\n");
}



int main() {
    NODE first=NULL;
    int elem,ch;
    while(1)
    {
        printf("Enter 1.insert front 2.insert rear 3.delete front 4.delete rear 5.display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter elemnt\n");
                scanf("%d",&elem);
                first=insert_front(first,elem);
                break;
            case 2:
                printf("Enter elemnt\n");
                scanf("%d",&elem);
                first=insert_rear(first,elem);
                break; 
            case 3:
                first=delete_front(first);
                break;
            case 4:
               first=delete_rear(first);
                break;
            case 5:
                display(first);
                break;
            default:
                printf("EXIT\n");
                exit(0);
        }
    }

    return 0;
}
