#include <iostream>
using namespace std;

int height,number,gcd,num,catall,catnum;
struct Node {int x,n;} a[100000];
long long sumh;
int GCD(int m,int n)
{
    int temp;
    while (n!=0)
    {
        temp=n;
        n=m%n;
        m=temp;
    }
    return m;
}
bool test(int p,int d)
{
    int dd=0,hh=height;
    while (hh!=1)
    {
        if (hh%(p+1)!=0)
            return 0;
        hh/=p+1;
        dd++;
    }
    return dd==d;
}
void count(int p)
{
    sumh=0;
    catall=0;
    catnum=1;
    while (height!=1)
    {
        catall+=catnum;
        sumh+=height*catnum;
        height/=p+1;
        catnum*=p;
    }
    sumh+=catnum;
    cout<<catall<<" "<<sumh<<endl;
}
int main()
{
    while (cin>>height>>number)
    {
        if (height==0&&number==0)
            break;
        if (number==1)
        {
            count(1);
            continue;
        }
        num=0;
        for (int i=2;i<=number;i++)
            if (number%i==0)
            {
                a[num].x=i;;
                a[num].n=0;
                while (number%i==0)
                {
                    number/=i;
                    a[num].n++;
                }
                num++;
            }
        gcd=a[0].n;
        for (int i=1;i<num;i++)
            gcd=GCD(max(gcd,a[i].n),min(gcd,a[i].n));
        int p=1;
        for (int i=0;i<num;i++)
            for (int j=0;j<a[i].n/gcd;j++)
                p*=a[i].x;
        if (test(p,gcd))
            count(p);
        else
        {
            int temp=gcd/2;
            for (;temp>=1;temp--)
                if (gcd%temp==0)
                {
                    int pp=1;
                    for (int j=0;j<gcd/temp;j++)
                        pp*=p;
                    if (test(pp,temp))
                    {
                        count(pp);
                        break;
                    }
                }
        }
    }
    return 0;
}
