#include <iostream>
#include <stdio.h>
#include <deque>
using namespace std;

int map[502][502],len[502][502],down[1000][2],num,r,maxx;
bool use[502][502];
int s[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
struct Node { int x, y, d; };
deque<Node> Q; // BFS 用佇列 
bool putin(int m)
{
    for (int j=1;j<=r;j++)
        for (int k=1;k<=r;k++)
        {
            int l;
            for (l=0;l<4;l++)
                if (map[j][k]>map[j+s[l][0]][k+s[l][1]])
                    break;
            if (l==4)
            {
                down[num][0]=j;
                down[num][1]=k;
                num++;
            }
            if (num>m)
                return 1;
        }
    return 0;
}
int main()
{
    int n,x,y,d,h;
    Node a;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            num=0;
            maxx=0;
            scanf("%d",&r);
            int m;
            scanf("%d",&m);
            for (int j=1;j<=r;j++)
                for (int k=1;k<=r;k++)
                {
                    scanf("%d",&map[j][k]);
                    use[j][k]=1;
                    len[j][k]=501*501+1;
                }
            for (int j=0;j<=r+1;j++)
            {
                map[0][j]=2147483647;
                map[j][0]=2147483647;
                map[r+1][j]=2147483647;
                map[j][r+1]=2147483647;
                use[0][j]=0;
                use[j][0]=0;
                use[r+1][j]=0;
                use[j][r+1]=0;
                len[0][j]=0;
                len[j][0]=0;
                len[r+1][j]=0;
                len[j][r+1]=0;
            }
            if (putin(m))
            {
                puts("Impossible");
                continue;
            }
            Q.clear();// 將所有幫浦位置放入佇列 
            int jj;
            for (jj=0,a.d=0;jj<num;jj++)
            {
                a.x=down[jj][0];
                a.y=down[jj][1];
                len[a.x][a.y]=0;
                Q.push_back(a);
            }
            while (Q.empty()==0) // BFS
            {
                a=Q.front();
                Q.pop_front();
                x=a.x, y=a.y, d=++a.d;
                h=map[x][y];
                for (int j=0;j<4;j++)
                    if ( map[x+s[j][0]][y+s[j][1]]>h&&len[x+s[j][0]][y+s[j][1]]>d )
                    {
                        len[x+s[j][0]][y+s[j][1]]=d;
                        a.x=x+s[j][0];
                        a.y=y+s[j][1];
                        Q.push_back(a);
                    }
            }
            for (int j=1;j<=r;j++)
                for (int k=1;k<=r;k++)
                    if (len[j][k]>maxx)
                        maxx=len[j][k];
            printf("%d\n",maxx);
        }
    }
    return 0;
}
