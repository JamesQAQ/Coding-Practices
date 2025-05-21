#include <iostream>
using namespace std;

int tree[1000][3],n,s;
void dfs(int x)
{
    printf("%d ",tree[x][0]);
    if (tree[x][1]>=0)
        dfs(tree[x][1]);
    if (tree[x][2]>=0)
        dfs(tree[x][2]);
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%d",&tree[i][0]);
            tree[i][1]=-1;
            tree[i][2]=-1;
            if (i==0)
                continue;
            s=0;
            if (tree[s][0]>tree[i][0])
            {
                if (tree[s][1]<0)
                {
                    tree[s][1]=i;
                    continue;
                }
                s=tree[s][1];
            }
            if (tree[s][0]<tree[i][0])
            {
                if (tree[s][2]<0)
                {
                    tree[s][2]=i;
                    continue;
                }
                s=tree[s][2];
            }
            while (1)
            {
                if (tree[s][0]>tree[i][0])
                {
                    if (tree[s][1]<0)
                    {
                        tree[s][1]=i;
                        break;
                    }
                    s=tree[s][1];
                }
                else
                {
                    if (tree[s][2]<0)
                    {
                        tree[s][2]=i;
                        break;
                    }
                    s=tree[s][2];
                }
            }
        }
        dfs(0);
        printf("\n");
    }
    return 0;
}
