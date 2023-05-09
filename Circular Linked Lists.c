#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node * link;

};
typedef struct node * NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("No memory available\n");
        exit(1);
    }
    return x;
}
NODE insert_front(NODE last,int elem)
{
    NODE temp;
    temp=getnode();
    temp->info=elem;
    if(last==NULL)
    {
        temp->link=temp;
        return temp;
    }
    temp->link=last->link;
    last->link=temp;
    return last;
}
NODE insert_rear(NODE last,int elem)
{
    NODE temp;
    temp=getnode();
    temp->info=elem;
    if(last==NULL)
    {
        temp->link=temp;
        return temp;
    }
    temp->link=last->link;
    last->link=temp;
    return temp;
}
NODE delete_front(NODE last)
{
    NODE first;
    if(last==NULL)
    {
        printf("No elements\n");
        return NULL;
    }
    if(last->link==last)
    {
        printf("%d is deleted\n",last->info);
        free(last);
        return NULL;
    }
    first=last->link;
    last->link=first->link;
    printf("%d is deleted\n ",first->info);
    free(first);
    return last;
}
NODE delete_rear(NODE last)
{
    NODE cur,first;
    if(last==NULL)
    {
        printf("No elements\n");
        return NULL;
    }
    if(last->link==last)
    {
        printf("%d is deleted\n",last->info);
        free(last);
        return NULL;
    }
    first=last->link;
    cur=last->link;
    while(cur->link!=last)
        cur=cur->link;
    cur->link=first;
    printf("%d is deleted\n",last->info);
    return cur;    

}
void display(NODE last)
{
    NODE cur=last->link;
    if(last==NULL)
    {
        printf("No elements\n");
        return ;
    }
    while(cur!=last)
    {
        printf("%d\t",cur->info);
        cur=cur->link;
    }
    printf("%d\t",cur->info);
    printf("\n");
}
int main() {
    NODE last=NULL;
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
                last=insert_front(last,elem);
                break;
            case 2:
                printf("Enter elemnt\n");
                scanf("%d",&elem);
                last=insert_rear(last,elem);
                break; 
            case 3:
                last=delete_front(last);
                break;
            case 4:
               last=delete_rear(last);
                break;
            case 5:
                display(last);
                break;
            default:
                printf("EXIT\n");
                exit(0);
        }
    }

    return 0;
}