#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a[10000],x,num=0;
    while (scanf("%d",&x)!=EOF)
    {
        num++;
        if (num==1)
            a[0]=x;
        else
        {
            int i;
            for (i=0;i<num;i++)
                if (x<a[i])
                {
                    for (int j=num-1;j>i;j--)
                        a[j]=a[j-1];
                    a[i]=x;
                    break;
                }
            if (i==num)
                a[num-1]=x;
        }
        if ((num-1)%2==0)
            printf("%d\n",a[num/2]);
        else
            printf("%d\n",(a[(num-2)/2]+a[num/2])/2);
    }    
    return 0;
}
