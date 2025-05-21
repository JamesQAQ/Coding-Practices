#include <iostream>
#include <stdio.h>
using namespace std;

int s[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char a[102][102];
void search(int x,int y)
{
    a[x][y]='+';
    for (int i=0;i<4;i++)
        if (a[x+s[i][0]][y+s[i][1]]=='-')
            search(x+s[i][0],y+s[i][1]);
}
int main()
{
    int n;
    memset(a,'+',sizeof(a));
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                cin>>a[i][j];
        int x,y;
        scanf("%d %d",&x,&y);
        search(x+1,y+1);
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
                printf("%c",a[i][j]);
            printf("\n");
        }
    }
    //system("pause");
    return 0;
}
