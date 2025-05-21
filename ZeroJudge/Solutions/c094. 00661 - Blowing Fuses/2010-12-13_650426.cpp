#include <iostream>
using namespace std;

int main()
{
    int n,m,c,maxx,now,t=0,a[20],temp;
    bool open[20],blow;
    while (cin>>n>>m>>c)
    {
        if (n==0&&m==0&&c==0)
            break;
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
            open[i]=0;
        }
        maxx=0;
        now=0;
        blow=0;
        for (int i=0;i<m;i++)
        {
            cin>>temp;
            temp--;
            if (open[temp]&&!blow)
            {
                now-=a[temp];
                open[temp]=0;
            }
            else if (!blow)
            {
                now+=a[temp];
                if (now>c)
                    blow=1;
                if (now>maxx)
                    maxx=now;
                open[temp]=1;
            }
        }
        cout<<"Sequence "<<++t<<endl;
        if (blow)
            cout<<"Fuse was blown."<<endl;
        else
        {
            cout<<"Fuse was not blown."<<endl;
            cout<<"Maximal power consumption was "<<maxx<<" amperes."<<endl<<endl;
        }
    }
    return 0;
}
