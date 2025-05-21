#include <iostream>
using namespace std;

string s[200];
int p[200][200],n,c;

int search(string e)
{
    int i;
    for (i=0;i<c;i++)
        if (s[i]==e)
            return i;
    if (i==c)
    {
        s[c]=e;
        c++;
        return i;
    }
}
int main()
{
    int r,x,y,xd=1;
    string a,b;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                p[i][j]=0;
        c=0;
        scanf("%d",&r);
        if ((n==0)&&(r==0))
            break;
        for (int i=0;i<r;i++)
        {
            cin>>a>>b;
            x=search(a);
            y=search(b);
            scanf("%d",&p[x][y]);
            p[y][x]=p[x][y];
        }
        for (int k=0;k<n;k++)
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                    p[i][j]=max(p[i][j],min(p[i][k],p[k][j]));
        cin>>a>>b;
        x=search(a);
        y=search(b);
        printf("Scenario #%d\n",xd);
        xd++;
        printf("%d tons\n",p[x][y]);
    }
    return 0;
}
