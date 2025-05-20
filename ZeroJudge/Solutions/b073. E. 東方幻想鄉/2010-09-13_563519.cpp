#include <iostream>
#include <stdio.h>
using namespace std;

int n,t,px,py;
int x,y,vx,vy;
bool between(int a,int b,int c)
{
    int x,y;
    x=(a>c)?a:c;
    y=(a>c)?c:a;
    if (x>=b)
        if (y<=b)
            return 1;
    return 0;
}
bool test()
{
    if (between(x,px,x+t*vx))
        if (between(y,py,y+t*vy))
            if ((py-y)*vx==vy*(px-x))
                return 1;
    return 0;
}
int main()
{
    bool r;
    while (scanf("%d",&n)!=EOF)
    {
        scanf("%d",&t);
        scanf("%d",&px);
        scanf("%d",&py);
        r=1;
        if ((n==0)&&(t==0)&&(px==0)&&(py==0))
            break;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&x);
            scanf("%d",&y);
            scanf("%d",&vx);
            scanf("%d",&vy);
            if(r)
                if (test())
                    r=0;
        }
        if (r)
            puts("false");
        else
            puts("true");
    }
    return 0;
}
