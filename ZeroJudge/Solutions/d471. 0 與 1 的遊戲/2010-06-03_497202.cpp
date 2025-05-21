#include <iostream>
using namespace std;

int main()
{
    int n,max=1,d=0,iii=0;
    int a[14]={0};
    while (cin>>n)
    {
        for (int i=0;i<n;i++)
            max*=2;
        for (int i=0;i<max;i++)
        {
            for (int ii=n-1;ii>=0;ii--)
                cout<<a[ii];
            cout<<endl;
            a[0]++;
            if (a[0]==2)
            {
                a[0]=0;
                a[1]++;
                while (a[1+iii]==2)
                {
                    a[1+iii]=0;
                    a[2+iii]++;
                    iii++;
                }
                iii=0;
            }
        }
        max=1;
        for (int i=0;i<14;i++)
            a[i]=0;
    }
    //system("pause");
    return 0;
}
