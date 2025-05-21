#include <iostream>
using namespace std;

struct Node {double x,y;};
int main()
{
    int num=1,t=0;
    Node a[11][2],b;
    char c;
    bool found;
    while (cin>>c)
    {
        if (c=='*')
            break;
        cin>>a[num][0].x>>a[num][0].y>>a[num][1].x>>a[num][1].y;
        if (a[num][0].x>a[num][1].x)
            swap(a[num][0].x,a[num][1].x);
        if (a[num][0].y>a[num][1].y)
            swap(a[num][0].y,a[num][1].y);
        num++;
    }
    while (cin>>b.x>>b.y)
    {
        if (b.x==9999.9&&b.y==9999.9)
            break;
        t++;
        found=0;
        for (int i=0;i<=num;i++)
            if (b.x<a[i][1].x&&b.x>a[i][0].x&&b.y<a[i][1].y&&b.y>a[i][0].y)
            {
                found=1;
                cout<<"Point "<<t<<" is contained in figure "<<i<<endl;;
            }
        if (!found)
            cout<<"Point "<<t<<" is not contained in any figure"<<endl;
    }
    return 0;
}
