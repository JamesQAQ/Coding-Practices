#include <iostream>
#include <deque>
using namespace std;

bool use[101][101][101];
struct Node {int x,y,z,d;};
deque <Node> Q;
int gcd(int m,int n)
{
    if (n==0)
        return m;
    return gcd(n,m%n);
}
int main()
{
    int a,b,c,ans;
    while (cin>>a>>b>>c)
    {
        if (a==0&&b==0&&c==0)
            break;
        int big=max(a,b),small=min(a,b);
        if (c%gcd(big,small)!=0)
        {
            cout<<"No"<<endl;
            continue;
        }
        for (int i=0;i<=a;i++)
            for (int j=0;j<=b;j++)
                for (int k=0;k<=c;k++)
                    use[i][j][k]=0;
        Node e;
        Q.clear();
        e.x=0;
        e.y=0;
        e.z=0;
        e.d=0;
        Q.push_back(e);
        use[0][0][0]=1;
        while (Q.empty()==0)
        {
            e=Q.front();
            Q.pop_front();
            int x=e.x,y=e.y,z=e.z,d=e.d;
            int xx=x,yy=y,zz=z,dd=d;
            z+=x;
            x=0;
            if (z==c)
            {
                ans=d+1;
                break;
            }
            if (z<c)
                if (!use[x][y][z])
                {
                    use[x][y][z]=1;
                    e.x=x;
                    e.y=y;
                    e.z=z;
                    e.d=d+1;
                    Q.push_back(e);
                }
            x=xx,y=yy,z=zz,d=dd;
            z+=y;
            y=0;
            if (z==c)
            {
                ans=d+1;
                break;
            }
            if (z<c)
                if (!use[x][y][z])
                {
                    use[x][y][z]=1;
                    e.x=x;
                    e.y=y;
                    e.z=z;
                    e.d=d+1;
                    Q.push_back(e);
                }
            x=xx,y=yy,z=zz,d=dd;
            x=0;
            if (!use[x][y][z])
            {
                use[x][y][z]=1;
                e.x=x;
                e.y=y;
                e.z=z;
                e.d=d+1;
                Q.push_back(e);
            }
            x=xx,y=yy,z=zz,d=dd;
            y=0;
            if (!use[x][y][z])
            {
                use[x][y][z]=1;
                e.x=x;
                e.y=y;
                e.z=z;
                e.d=d+1;
                Q.push_back(e);
            }
            x=xx,y=yy,z=zz,d=dd;
            x=a;
            if (!use[x][y][z])
            {
                use[x][y][z]=1;
                e.x=x;
                e.y=y;
                e.z=z;
                e.d=d+1;
                Q.push_back(e);
            }
            x=xx,y=yy,z=zz,d=dd;
            y=b;
            if (!use[x][y][z])
            {
                use[x][y][z]=1;
                e.x=x;
                e.y=y;
                e.z=z;
                e.d=d+1;
                Q.push_back(e);
            }
            x=xx,y=yy,z=zz,d=dd;
            if (x>b-y)
            {
                x-=b-y;
                y=b;
            }
            else
            {
                y+=x;
                x=0;
            }
            if (!use[x][y][z])
            {
                use[x][y][z]=1;
                e.x=x;
                e.y=y;
                e.z=z;
                e.d=d+1;
                Q.push_back(e);
            }
            x=xx,y=yy,z=zz,d=dd;
            if (y>a-x)
            {
                y-=a-x;
                x=a;
            }
            else
            {
                x+=y;
                y=0;
            }
            if (!use[x][y][z])
            {
                use[x][y][z]=1;
                e.x=x;
                e.y=y;
                e.z=z;
                e.d=d+1;
                Q.push_back(e);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
