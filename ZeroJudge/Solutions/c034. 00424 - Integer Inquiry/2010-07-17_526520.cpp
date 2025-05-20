#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int sum[150]={};
    string s;
    while (cin>>s)
    {
        int n=s.length();
        if ((n==1)&&(s[0]=='0'))
        {
            int y;
            for (y=149;y>0;y--)
                if (sum[y]!=0)
                {
                    printf("%d",sum[y]);
                    break;
                }
            y--;
            for (;y>0;y--)
                printf("%d",sum[y]);
            printf("%d\n",sum[0]);
            memset(sum,0,sizeof(sum));
        }
        else
        {
            int j=0;
            for (int i=n-1;i>=0;i--)
                sum[j++]+=s[i]-48;
            for (int i=0;i<100;i++)
                if (sum[i]>=10)
                {
                    sum[i+1]+=sum[i]/10;
                    sum[i]%=10;
                }
        }
    }
    //system("pause");
    return 0;
}
