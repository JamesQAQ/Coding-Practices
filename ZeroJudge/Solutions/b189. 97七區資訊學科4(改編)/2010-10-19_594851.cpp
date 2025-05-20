#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,negative;
    char s[33];
    double sum=0;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=1;i<=n;i++)
        {
            scanf("%s",&s);
            if (s[0]=='1')
                negative=-1;
            else
                negative=1;
            int z=0;
            for (int j=1;j<=8;j++)
                z=z*2+s[j]-48;
            z=z-127;
            double a=0;
            for (int j=31;j>=9;j--)
                a=a/2+s[j]-48;
            a/=2;
            a+=1;
            double temp=1;
            if (z>0)
            {
                for (int j=0;j<z;j++)
                    a*=2;
            }
            else if (z<0)
            {
                z=abs(z);
                for (int j=0;j<z;j++)
                    a/=2;
            }
            a*=negative;
            cout<<"字串"<<i<<" "<<s<<" = "<<a<<endl;
            sum+=a;
        }
        cout<<"總和為"<<sum<<endl;
    }
    return 0;
}
