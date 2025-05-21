#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x,y,xx,yy;
    while (cin>>x>>y>>xx>>yy)
    {
        if (x==0&&y==0&&xx==0&&yy==0)
            break;
        if (x==xx&&y==yy)
            puts("0");
        else if (x==xx||y==yy||abs(x-xx)==abs(y-yy))
            puts("1");
        else
            puts("2");
    }
    return 0;
}
