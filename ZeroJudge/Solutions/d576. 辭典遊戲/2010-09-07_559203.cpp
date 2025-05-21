#include <iostream>
#include <stdio.h>
using namespace std;

int a[4][4],suma,sumb,n,wina,winb,draw;
bool b[4][4];
void adfs(int y);
void bdfs(int x)//B取 
{
    int i;
    for (i=0;i<n;i++)
        if (b[i][x])
            break;
    if (i==n)
    {
        if (suma>sumb)
            wina++;
        else if (sumb>suma)
            winb++;
        else
            draw++;
        return;
    }
    for (i=0;i<n;i++)
        if (b[i][x])
        {
            sumb+=a[i][x];
            b[i][x]=0;
            adfs(i);
            b[i][x]=1;
            sumb-=a[i][x];
        }
}
void adfs(int y)//A取 
{
    int i;
    for (i=0;i<n;i++)
        if (b[y][i])
            break;
    if (i==n)
    {
        if (suma>sumb)
            wina++;
        else if (sumb>suma)
            winb++;
        else
            draw++;
        return;
    }
    for (i=0;i<n;i++)
        if (b[y][i])
        {
            suma+=a[y][i];
            b[y][i]=0;
            bdfs(i);
            b[y][i]=1;
            suma-=a[y][i];
        }
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        suma=0;
        sumb=0;
        wina=0;
        winb=0;
        draw=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        memset(b,1,sizeof(b));
        for (int i=0;i<n;i++)
        {
            suma+=a[0][i];
            b[0][i]=0;
            bdfs(i);
            b[0][i]=1;
            suma-=a[0][i];
        }
        printf("%d %d %d\n",wina,winb,draw);
    }
    return 0;
}
