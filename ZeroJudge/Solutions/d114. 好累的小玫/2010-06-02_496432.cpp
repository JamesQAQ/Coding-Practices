#include <iostream>
using namespace std;

int main()
{  
    int a[10000]={1},res[10000]={};
    for (int i=2;i<=100;i++)
    {
        for (int o=2;o<=i;o++)
        {
            for (int p=0;p<10000;p++)
            {
                res[p]+=a[p]*o;
                if (res[p]>=10)
                {
                    res[p+2]+=res[p]/100;
                    res[p]%=100;
                    res[p+1]+=res[p]/10;
                    res[p]%=10;
                }
            }
            for (int i=9999;i>=0;i--)
            {
                a[i]=res[i];
                res[i]=0;
            }
        }
    }
    int i;
    for (i=9999;i>=0;i--)
    {
        if (a[i]!=0)
        {
            cout<<a[i]<<endl;
            break;
        }
    }
    i--;
    for (;i>=0;i--)
        cout<<a[i]<<endl;
    //system("pause");
    return 0;
}
