#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
    int n;
    double ax,ay,bx,by,cx,cy;
    while (scanf("%d",&n)==1)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%lf %lf %lf %lf %lf %lf",&ax,&ay,&bx,&by,&cx,&cy);
            printf("%.0lf\n",abs(ax*by-ay*bx+bx*cy-by*cx+cx*ay-cy*ax)/14);
        }
    }
    return 0;
}
