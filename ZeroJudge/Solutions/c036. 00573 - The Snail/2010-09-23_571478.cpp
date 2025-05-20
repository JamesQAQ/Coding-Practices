#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    double at,U,H,D,F;
    int day;
    while (scanf("%lf %lf %lf %lf",&H,&U,&D,&F))
    {
        F=U*F/100;
        if (H==0)
            break;
        at=0;
        day=0;
        while (1)
        {
            day++;
            if (U>0)
            {
                at+=U;
                U-=F;
            }
            if (at>H)
            {
                printf("success on day %d\n",day);
                break;
            }
            at-=D;
            if (at<0)
            {
                printf("failure on day %d\n",day);
                break;
            }
        }
    }
    return 0;
}
