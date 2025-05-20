#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
    int a,b,temp,ans1,ans2;
    while (scanf("%d %d",&a,&b))
    {
        if (a==0&&b==0)
            break;
        ans1=0;
        ans2=0;
        if (a>b)
        {
            temp=a;
            a=b;
            b=temp;
        }
        double c=sqrt(b*b-a*a);
        if (floor(c)==ceil(c))
            ans1=floor(c);
        c=sqrt(a*a+b*b);
        if (floor(c)==ceil(c))
            ans2=floor(c);
        if (ans1>ans2)
        {
            temp=ans1;
            ans1=ans2;
            ans2=temp;
        }
        if (ans1>0)
            printf("%d\n",ans1);
        if (ans2>0)
            printf("%d\n",ans2);
        if (ans1==0&&ans2==0)
            puts("Wrong");
    }
    return 0;
}
