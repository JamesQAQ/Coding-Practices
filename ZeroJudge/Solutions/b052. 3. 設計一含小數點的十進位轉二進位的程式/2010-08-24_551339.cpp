#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a,num;
    double b;
    bool s[30];
    while (cin>>b)
    {
        num=0;
        a=(int)b/1;
        b-=a;
        if (a==0)
            printf("0");
        else
        {
            while (a!=0)
            {
                s[num]=a%2;
                a=(a-s[num])/2;
                num++;
            }
            for (int i=num-1;i>=0;i--)
                printf("%d",s[i]);
        }
        printf(".");
        while (b!=0)
        {
            b*=2;
            if (b>=1)
            {
                printf("1");
                b-=1;
            }
            else
                printf("0");
        }
        printf("\n");
    }
    //system("pause");
    return 0;
}
