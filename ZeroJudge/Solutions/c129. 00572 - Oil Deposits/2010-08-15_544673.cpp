#include <iostream>
#include <stdio.h>
using namespace std;

int n,m;
int s[8][2]={{-1,-1},
            {0,-1},
            {1,-1},
            {1,0},
            {1,1},
            {0,1},
            {-1,1},
            {-1,0}};
char a[101][101];
void search(int i,int j)
{
    a[i][j]='*';
    for (int x=0;x<8;x++)
        if (a[i+s[x][0]][j+s[x][1]]=='@')
            search(i+s[x][0],j+s[x][1]);
}
int main()
{
    while (scanf("%d",&m)!=EOF)
    {
        scanf("%d",&n);
        if ((m==0)&&(n==0))
            break;
        int sum=0;
        for (int i=1;i<=m;i++)
            for (int j=1;j<=n;j++)
                cin>>a[i][j];
        for (int i=1;i<=m;i++)
            for (int j=1;j<=n;j++)
                if (a[i][j]=='@')
                {
                    search(i,j);
                    sum++;
                }
        printf("%d\n",sum);
    }
    //system ("pause");
    return 0;
}
