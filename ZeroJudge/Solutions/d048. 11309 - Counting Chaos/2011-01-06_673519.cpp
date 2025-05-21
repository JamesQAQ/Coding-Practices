#include <iostream>
using namespace std;

int main()
{
    int num=0,a[85],b,c,t,at;
    for (int i=0;i<=9;i++)
        a[num++]=i;
    for (int i=1;i<=5;i++)
        a[num++]=i*10+i;
    for (int i=1;i<=9;i++)
        for (int j=0;j<=5;j++)
            a[num++]=i*100+j*10+i;
    for (int i=0;i<=5;i++)
        a[num++]=1001+i*100+i*10;
    for (int i=0;i<=3;i++)
        a[num++]=2002+i*100+i*10;
    cin>>t;
    while (t-->0)
    {
        char temp;
        cin>>b>>temp>>c;
        b=b*100+c;
        at=0;
        while (a[at]<=b)
        {
            at++;
            if (at==num)
            {
                at=0;
                break;
            }
        }
        printf("%02d:%02d\n",a[at]/100,a[at]%100);
    }
    return 0;
}
