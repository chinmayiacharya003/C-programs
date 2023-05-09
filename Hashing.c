#include<stdio.h>
#include<stdlib.h>
#define hts 3
int getKey(int value)
{
    return value%hts;
}
struct Employee
{
    char name[10];
    int id;
};
typedef struct Employee E;
struct Hash
{
    int flag;
    long int add;
};
typedef struct Hash H;

void hash_table(FILE *file,H table[hts],int n)
{
    E e;
    int index,count;
    for(int i=0;i<n;i++)
    {
        printf("Enter Employee name and id\n ");
        scanf("%s%d",e.name,&(e.id));
        index=getKey(e.id);
        count=index;
        while(table[index].flag!=-1)
        {
            printf("Linear probing\n");
            index=(index+1)%hts;
            if(count==index)
            {
                printf("No place in hash table\n");
                return;
            }
        }
        table[index].flag=e.id;
        fseek(file,0,SEEK_END);
        table[index].add=ftell(file);
        fwrite(&e,sizeof(E),1,file);
        printf("Hash table: \n");
        printf("Index - %d Name - %s Id - %d\n",index,e.name,e.id);
    }
}
int main()
{
    
    FILE *file;
    H h[hts];
    int n;
    printf("Enter the number of emplyoees\n");
    scanf("%d",&n);
    for(int i=0;i<hts;i++)
        h[i].flag=-1;
    file=fopen("Emp.txt","w+");    
    hash_table(file,h,n);
    fclose(file);
    return 0;    
}
