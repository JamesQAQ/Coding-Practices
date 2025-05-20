#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
    int n,x,y;
    while (scanf("%d",&n))
    {
        if (n==0)
            break;
        int d=(int)sqrt(n);
        if (d%2==0)
        {
            int len=n-d*d;
            if (len>0)
            {
                if (len>d+1)
                    printf("%d %d\n",2*(d+1)-len,d+1);
                else
                    printf("%d %d\n",d+1,len);
            }
            else
                printf("%d %d\n",d,1);
        }
        else
        {
            int len=n-d*d;
            if (len>0)
            {
                if (len>d+1)
                    printf("%d %d\n",d+1,2*(d+1)-len);
                else
                    printf("%d %d\n",len,d+1);
            }
            else
                printf("%d %d\n",1,d);
        }
    }
    return 0;
}
