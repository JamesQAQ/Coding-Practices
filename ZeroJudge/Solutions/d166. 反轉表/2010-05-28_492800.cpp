#include <iostream>
using namespace std;

int main()
{
    string ss;
    int c,t=0;
    int a[100]={0};
    int s[51]={0};
    int nn=0,k=0;
    for (int i=0;i<100;i++)
        a[i]=51;
    while (getline(cin,ss))
    {
        if (ss[0]==45)
            break;
        int n=ss.length();
        for (int i=0;i<n;i++)
        {
            if (ss[i]==32)
            {
                s[nn]+=k;
                k=0;
                nn++;
            }
            else
                k=k*10+ss[i]-48;   
        }
        s[nn]+=k;
        k=0;
        nn++;
        for (int i=0;i<nn;i++)
        {
            c=s[i];
            for (int ii=0;ii<50;ii++)
            {
                if (c==0)
                {
                    while (a[ii]!=51)
                        ii++;
                    a[ii]=i+1;
                    break;
                }
                if (i<a[ii])
                    t++;
                if (t==c)
                {
                    ii++;
                    while (a[ii]!=51)
                        ii++;
                    a[ii]=i+1;
                    break;
                }
            }
            t=0;
        }
        for (int i=0;i<nn;i++)
            cout<<a[i]<<" ";
        cout<<endl;
        for (int i=0;i<100;i++)
            a[i]=51;
        for (int i=0;i<51;i++)
            s[i]=0;
        nn=0;
    }
    //system("pause");
    return 0;
}
