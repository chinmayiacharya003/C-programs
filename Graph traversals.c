#include<stdio.h>
#include<stdlib.h>
int a[10][10],f[10];
void read_mat(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    

}
void dfs(int u,int n)
{
    int v,S[10],top=-1;
    S[++top]=u;
    //printf("%d\t",u);
    f[u]=0;
    while(top!=-1)
    {
        u=S[top--];
        printf("%d\t",u);
        for(v=0;v<n;v++)
        {
            if(a[u][v]==1&&f[v]==0)
            {
                S[++top]=v;
                f[v]=1;
            }
        }
    }
    printf("\n");
}
void bfs(int u,int n)
{
    int v,Q[10],fr=0,r=-1;
    Q[++r]=u;
    f[u]=1;
    printf("%d\t",u);
    while(fr<=r)
    {
        u=Q[fr++];
        for(v=0;v<n;v++)
        {
            if(a[u][v]==1&&f[v]==0)
            {
                printf("%d\t",v);
                Q[++r]=v;
                f[v]=1;
            }
        }
    }
    printf("\n");
}

int main()
{
    int n,i,source;
    printf("Enter number of nodes\n");
    scanf("%d",&n);
    read_mat(n);
    printf("Adjecency matrix is read\n");
    printf("DFS\n");
    for(source=0;source<n;source++)
    {
        for(i=0;i<n;i++)
            f[i]=0;
        printf("Nodes reachable from %d : ",source);
        dfs(source,n);    
    }
    printf("BFS\n");
    for(source=0;source<n;source++)
    {
        for(i=0;i<n;i++)
            f[i]=0;
        printf("Nodes reachable from %d : ",source);
        bfs(source,n);    
    }
}