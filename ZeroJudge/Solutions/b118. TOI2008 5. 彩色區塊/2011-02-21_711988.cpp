#include <iostream>
using namespace std;

struct Node {int x,y;} r[200][2];
struct Color {int r,g,b;} ans[100000],rc[200];
int area[100000];
int main()
{
    int x[201],xnum,y[201],ynum,n,maxx,anum;
    bool xx[1001]={},yy[1001]={};
    while (cin>>n)
    {
        for (int i=0;i<n;i++)
        {
            cin>>r[i][0].x>>r[i][0].y>>r[i][1].x>>r[i][1].y;
            if (r[i][0].x>r[i][1].x)
                swap(r[i][0].x,r[i][1].x);
            if (r[i][0].y>r[i][1].y)
                swap(r[i][0].y,r[i][1].y);
            xx[r[i][0].x]=xx[r[i][1].x]=yy[r[i][0].y]=yy[r[i][1].y]=1;
            cin>>rc[i].r>>rc[i].g>>rc[i].b;
        }
        xnum=0;
        ynum=0;
        for (int i=0;i<=1000;i++)
        {
            if (xx[i])
                x[xnum++]=i;
            if (yy[i])
                y[ynum++]=i;
        }
        anum=0;
        for (int i=0;i<xnum-1;i++)
            for (int j=0;j<ynum-1;j++)
            {
                Color t;
                t.r=t.g=t.b=0;
                int temp=0;
                for (int k=0;k<n;k++)
                    if (r[k][0].x<=x[i]&&r[k][1].x>=x[i+1]&&r[k][0].y<=y[j]&&r[k][1].y>=y[j+1])
                    {
                        temp++;
                        t.r+=rc[k].r;
                        t.g+=rc[k].g;
                        t.b+=rc[k].b;
                    }
                if (temp!=0)
                {
                    t.r=(t.r%temp)?t.r/temp+1:t.r/temp;
                    t.g=(t.g%temp)?t.g/temp+1:t.g/temp;
                    t.b=(t.b%temp)?t.b/temp+1:t.b/temp;
                    int d;
                    for (d=0;d<anum;d++)
                        if (t.r==ans[d].r&&t.g==ans[d].g&&t.b==ans[d].b)
                            break;
                    if (d==anum)
                    {
                        area[anum]=0;
                        ans[anum++]=t;
                    }
                    area[d]+=(x[i+1]-x[i])*(y[j+1]-y[j]);
                }
            }
        maxx=0;
        for (int i=1;i<anum;i++)
            if (area[i]>area[maxx])
                maxx=i;
        cout<<ans[maxx].r<<" "<<ans[maxx].g<<" "<<ans[maxx].b<<endl;
        for (int i=0;i<xnum;i++)
            xx[x[i]]=0;
        for (int i=0;i<ynum;i++)
            yy[y[i]]=0;
    }
    return 0;
}
