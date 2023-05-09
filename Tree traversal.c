#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node * llink,*rlink;
    int info;
};
typedef struct node * NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    return x;
    
}
NODE insert_bst(NODE root,int elem)
{
    NODE temp=getnode();
    temp->info=elem;
    temp->rlink=temp->llink=NULL;
    if(root==NULL)
        return temp;
    NODE cur=root,par=NULL;
    while(cur!=NULL)
    {
        par=cur;
        if(elem>cur->info)
            cur=cur->rlink;
        else    
            cur=cur->llink;    
    }    
    if(elem>par->info)
        par->rlink=temp;
    else
        par->llink=temp; 
    return root;       
}
void preorder(NODE root)
{
    if(root==NULL)   return;
    printf("%d\t",root->info);
    preorder(root->llink);
    preorder(root->rlink);
}
void inorder(NODE root)
{
    if(root==NULL)   return;
    
    inorder(root->llink);
    printf("%d\t",root->info);
    inorder(root->rlink);
}
void postorder(NODE root)
{
    if(root==NULL)   return;
    
    postorder(root->llink);
    
    postorder(root->rlink);
    printf("%d\t",root->info);
}
int main()
{
    NODE root=NULL;
    int ch,elem;
    while(1)
    {
        printf("Enter 1.Insert 2.Preorder 3.Inoreder 4.Postorder\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter elem\n");
            scanf("%d",&elem);
            root=insert_bst(root,elem);
            break;
            case 2:preorder(root);
            printf("\n");
            break;
            case 3: inorder(root);
            printf("\n");
            break;
            case 4: postorder(root);
            printf("\n");
            break;
            default:printf("EXIT\n");
            exit(0);
            
        }
    }
}