#include <iostream>
#include <cmath>
using namespace std;
#define MAX 1000000
int upf[MAX],uph[MAX],upg[MAX],dof[MAX],doh[MAX],dog[MAX];
bool uupf[MAX],uuph[MAX],uupg[MAX],udof[MAX],udoh[MAX],udog[MAX];
int g(int z)
{
    if (z<0)
    {
        int zz=abs(z);
        if (udog[zz])
            return dog[zz];
        udog[zz]=1;
        return dog[zz]=z*z-1;
    }
    if (uupg[z])
        return upg[z];
    uupg[z]=1;
    if (z<=2)
        return upg[z]=z*z-1;
    else
        return upg[z]=2;
}
int h(int y)
{
    if (y<0)
    {
        int yy=abs(y);
        if (udoh[yy])
            return dog[yy];
        udoh[yy]=1;
        return dog[yy]=-1;
    }
    if (uuph[y])
        return uph[y];
    uuph[y]=1;
    if (y<2)
        return uph[y]=-1;
    else
        return uph[y]=2+h(y-1)-h(y-2);
}
int f(int x)
{
    if (x<0)
    {
        int xx=abs(x);
        if (udof[xx])
            return dof[xx];
        udof[xx]=1;
        int hh=h(x);
        if (x>hh)
            return dof[xx]=f(x-1)-hh;
        else if (x<hh)
        {
            int gg=g(x);
            return dof[xx]=f(gg)-gg;
        }
        else
            return dof[xx]=1;
    }
    if (uupf[x])
        return upf[x];
    uupf[x]=1;
    int hh=h(x);
    if (x>hh)
        return upf[x]=f(x-1)-hh;
    else if (x<hh)
    {
        int gg=g(x);
        return upf[x]=f(gg)-gg;
    }
    else
        return upf[x]=1;
}
int main()
{
    memset(uupf,0,sizeof(uupf));
    memset(uupf,0,sizeof(uuph));
    memset(uupf,0,sizeof(uupg));
    memset(uupf,0,sizeof(udof));
    memset(uupf,0,sizeof(udof));
    memset(uupf,0,sizeof(udof));
    int x;
    while (cin>>x)
        cout<<f(x)<<endl;
    return 0;
}
