#include <iostream>
using namespace std;

int main()
{
    string s;
    int p,d=0,dot=0,cut=0;
    double sum1=0,sum2=0,k=0,n;
    while (getline(cin,s))
    {
        n=s.length();
        p=s.find(":");
        if (p!=-1)
            s.replace(p,1,"-");
        while (p<string::npos)
        {
            for (int i=p+1;i<n;i++)
            {
                if (s[i]==32)
                {
                    for (int ii=0;ii<d;ii++)
                        k=k/10;
                    if (s[p-1]%2==1)
                    {
                        if (cut==0)
                            sum1+=k;
                        else
                            sum1-=k;
                    }
                    else
                    {
                        if (cut==0)
                            sum2+=k;
                        else
                            sum2-=k;
                    }
                    break;
                }
                else if (s[i]==46)
                    dot=1;
                else if (s[i]==45)
                    cut=1;
                else
                {
                    k=k*10+s[i]-48;
                    if (dot==1)
                        d++;
                }
            }
            if (s[p-1]%2==1)
            {
                p=s.find(":");
                if (p==-1)
                {
                    for (int ii=0;ii<d;ii++)
                        k=k/10;
                    if (cut==0)
                        sum1+=k;
                    else
                        sum1-=k;
                }
            }
            else
            {
                p=s.find(":");
                if (p==-1)
                {
                    for (int ii=0;ii<d;ii++)
                        k=k/10;
                    if (cut==0)
                        sum2+=k;
                    else
                        sum2-=k;
                }
            }
            if (p!=-1)
                s.replace(p,1,"-");
            dot=0;
            d=0;
            k=0;
            cut=0;
        }
        cout<<sum1-sum2<<endl;
        sum1=0;
        sum2=0;
    }
    //system("pause");
    return 0;
}
