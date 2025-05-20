#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
    double d,l;
    while (scanf("%lf",&d)!=EOF)
    {
        scanf("%lf",&l);
        printf("%.3lf\n",sqrt(l*l/4-d*d/4)*(l/2)*2*acos(0.0));
    }
    return 0;
}
