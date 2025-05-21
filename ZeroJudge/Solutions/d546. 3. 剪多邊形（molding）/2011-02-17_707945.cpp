#include <iostream>
#include <cmath>
using namespace std;

struct Node{int x,y;} a[20];

int cross(Node o,Node a,Node b)
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
bool far(Node o,Node a,Node b)
{
    return (a.x-o.x)*(a.x-o.x)+(a.y-o.y)*(a.y-o.y)>(b.x-o.x)*(b.x-o.x)+(b.y-o.y)*(b.y-o.y);
}
int main()
{
    int b[20],m,n,hullsum,sum,area;
    while (cin>>n>>area)
    {
        area*=2;
        for (int i=0;i<n;i++)
            cin>>a[i].x>>a[i].y;
        sum=0;
        for (int i=0;i<n-1;i++)
            sum+=a[i].x*a[i+1].y-a[i].y*a[i+1].x;
        sum+=a[n-1].x*a[0].y-a[n-1].y*a[0].x;
        sum=abs(sum);
        b[0]=0;
        m=1;
        while (1)
        {
            int next=0;
            for (int i=1;i<n;i++)
            {
                int c=cross(a[b[m-1]],a[i],a[next]);
                if (i!=b[m-1]&&c>=0)
                    next=i;
            }
            if (next==0)
                break;
            b[m++]=next;
        }
        hullsum=0;
        for (int i=0;i<m-1;i++)
            hullsum+=a[b[i]].x*a[b[i+1]].y-a[b[i]].y*a[b[i+1]].x;
        hullsum+=a[b[m-1]].x*a[b[0]].y-a[b[m-1]].y*a[b[0]].x;
        hullsum=abs(hullsum);
        cout<<(((hullsum-sum)%area)?(hullsum-sum)/area+1:(hullsum-sum)/area)<<endl;
    }
    return 0;
}
