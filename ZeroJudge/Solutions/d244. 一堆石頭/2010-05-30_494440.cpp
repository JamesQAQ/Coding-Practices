#include <iostream>
using namespace std;

int main()
{
    int a[1000],b[1000]={};
    int i=0,k=0,c=0;
    string s;
    while (getline(cin,s))
    {
        int n=s.length();
        for (int ii=0;ii<n;ii++)
        {
            if (s[ii]!=32)
                k=k*10+s[ii]-48;
            else
            {
                for (int iii=0;iii<i;iii++)
                {
                    if (k==a[iii])
                    {
                        b[iii]++;
                        c=1;
                        break;
                    }
                }
                if (c==0)
                {
                    a[i]=k;
                    b[i]++;
                    i++;
                }
                k=0;
                c=0;
            }
        }
        for (int iii=0;iii<i;iii++)
        {
            if (k==a[iii])
            {
                b[iii]++;
                c=1;
                break;
            }
        }
        if (c==0)
        {
            a[i]=k;
            b[i]++;
            i++;
        }
        k=0;
        c=0;
        for (int ii=0;ii<i;ii++)
            if (b[ii]==2)
            {
                cout<<a[ii]<<endl;
                break;
            }
        for (int ii=0;ii<i;ii++)
            b[ii]=0;
        i=0;
    }
    //system("pause");
    return 0;
}
