
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct Employee
{
    char name[20];
    int id;
};
typedef struct Employee E;
struct node
{
    struct node * llink,*rlink;
    E info;
};
typedef struct node * NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    return x;
    
}

NODE insert_front(NODE first,E e)
{
    NODE temp;
    temp=getnode();
    strcpy((temp->info).name,e.name);
    (temp->info).id=e.id;
    temp->llink=NULL;
    temp->rlink=NULL;
    if(first==NULL)
        return temp;
    temp->rlink=first;
    first->llink=temp;
    return temp;
}
NODE insert_rear(NODE first,E e)
{
    NODE temp;
   strcpy((temp->info).name,e.name);
    (temp->info).id=e.id;
    temp->rlink=temp->llink=NULL;
    if(first==NULL)
        return temp;
    NODE cur=first;
    while(cur->rlink!=NULL)
        cur=cur->rlink;
    temp->llink=cur;
    cur->rlink=temp;
    return first;        
}
NODE delete_front(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("Empty\n");
        return NULL;
    }
    if(first->rlink==NULL)
    {
        printf("Employee deleted : %s (Id-%d)\n",(first->info).name,(first->info).id);
        free(first);
        return NULL;
    }
    temp=first->rlink;
    printf("Employee deleted : %s (Id-%d)\n",(first->info).name,(first->info).id);
    temp->llink=NULL;
    return temp;
}
void count(NODE first)
{
    NODE cur=first;
    int c=0;
    if(first==NULL)
    {
        printf("Number of nodes -%d\n",c);
        return;
    }
    while(cur!=NULL)
    {
        cur=cur->rlink;
        c++;
    }
    printf("Number of nodes -%d\n",c);

}
void display(NODE first)
{
    if(first==NULL)
    {
        printf("No elements\n");
        return;
    }
    NODE cur;
    cur=first;
    while(cur!=NULL)
    {
        printf("Name - %s\t",(cur->info).name);
        printf("Id - %d\n",(cur->info).id);
        cur=cur->rlink;
    }printf("\n");
}
int main() {
    NODE first=NULL;
    int ch;
    E e;
    while(1)
    {
        printf("Enter 1.DLL stack 2.DLL queue 3.Count\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Implementing stack\n");
                printf("Push: \n");
                printf("Enter Employee name and id\n");
                scanf("%s %d",e.name,&e.id);
                first=insert_front(first,e);
                display(first);
                printf("Pop: \n");
                first=delete_front(first);
                display(first);
                break;
            case 2:    
                printf("Implementing queue\n");
                printf("Insert: \n");
                printf("Enter Employee name and id\n");
                scanf("%s %d",e.name,&e.id);
                first=insert_rear(first,e);
                display(first);
                printf("Delete: \n");
                first=delete_front(first);
                display(first);
                break;
            case 3:
                count(first);
                break;
            default:
                printf("EXIT\n");
                exit(0);        

        }
    }
    return 0;
}
