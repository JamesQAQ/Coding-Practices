#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,r,g,b;
    double x,y,z,sumy;
    while (scanf("%d",&n)!=EOF)
    {
        sumy=0;
        for (int i=0;i<n*n;i++)
        {
            scanf("%d %d %d",&r,&g,&b);
            x=(double)0.5149*r+0.3244*g+0.1607*b;
            y=(double)0.2654*r+0.6704*g+0.0642*b;
            z=(double)0.0248*r+0.1248*g+0.8504*b;
            printf("%.4lf %.4lf %.4lf\n",x,y,z);
            sumy+=y;
        }
        printf("The average of Y is %.4lf\n",(double)sumy/(n*n));
    }
    return 0;
}
