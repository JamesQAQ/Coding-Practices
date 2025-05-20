#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int max,x,y,left,right;
    while (scanf("%d %d",&x,&y)!=EOF)
    {
        left=(x<y)?x:y;
        right=(x>y)?x:y;
        max=0;
        for (int i=left;i<=right;i++)
        {
            int n=i,sum=1;
            while (n!=1)
            {
                sum++;
                if (n%2==1)
                    n=3*n+1;
                else
                    n/=2;
            }
            if (sum>max)
                max=sum;
        }
        printf("%d %d %d\n",x,y,max);
    }
    return 0;
}
