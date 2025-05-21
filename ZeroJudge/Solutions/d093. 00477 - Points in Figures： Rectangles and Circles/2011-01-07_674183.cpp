#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num=1,t=0;
    double a[11][4],x,y;
    char c[12];
    bool found;
    while (cin>>c[num])
    {
        if (c[num]=='*')
            break;
        if (c[num]=='r')
        {
            cin>>a[num][0]>>a[num][1]>>a[num][2]>>a[num][3];
            if (a[num][0]>a[num][2])
                swap(a[num][0],a[num][2]);
            if (a[num][1]>a[num][3])
                swap(a[num][1],a[num][3]);
        }
        else
            cin>>a[num][0]>>a[num][1]>>a[num][2];
        num++;
    }
    while (cin>>x>>y)
    {
        if (x==9999.9&&y==9999.9)
            break;
        t++;
        found=0;
        for (int i=1;i<num;i++)
        {
            if (c[i]=='r')
            {
                if (x<a[i][2]&&x>a[i][0]&&y<a[i][3]&&y>a[i][1])
                {

                    found=1;
                    cout<<"Point "<<t<<" is contained in figure "<<i<<endl;;
                }
            }
            else
            {
                double dx=x-a[i][0],dy=y-a[i][1];
                if (sqrt(dx*dx+dy*dy)<a[i][2])
                {
                    found=1;
                    cout<<"Point "<<t<<" is contained in figure "<<i<<endl;;
                } 
            }
        }
        if (!found)
            cout<<"Point "<<t<<" is not contained in any figure"<<endl;
    }
    return 0;
}
