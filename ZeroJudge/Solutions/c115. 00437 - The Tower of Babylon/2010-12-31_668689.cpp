#include <iostream>
#include <algorithm>
using namespace std;

struct Node {int x,y,h,dp;} a[90];

bool cmp(Node i,Node j)
{
    return i.x*i.y<j.x*j.y;
}
int main()
{
    int n,b[3],ans,t=0;
    while (cin>>n)
    {
        if (n==0)
            break;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<3;j++)
                cin>>b[j];
            sort(b,b+3);
            a[3*i].x=b[0];
            a[3*i].y=b[1];
            a[3*i].h=a[3*i].dp=b[2];
            a[3*i+1].x=b[1];
            a[3*i+1].y=b[2];
            a[3*i+1].h=a[3*i+1].dp=b[0];
            a[3*i+2].x=b[0];
            a[3*i+2].y=b[2];
            a[3*i+2].h=a[3*i+2].dp=b[1];
        }
        stable_sort(a,a+3*n,cmp);
        ans=0;
        for (int i=1;i<3*n;i++)
            for (int j=0;j<i;j++)
                if (a[j].x<a[i].x&&a[j].y<a[i].y&&a[j].dp+a[i].h>a[i].dp)
                {
                    a[i].dp=a[j].dp+a[i].h;
                    if (a[i].dp>ans)
                        ans=a[i].dp;
                }
        cout<<"Case "<<++t<<": maximum height = "<<ans<<endl;
    }
    return 0;
}
