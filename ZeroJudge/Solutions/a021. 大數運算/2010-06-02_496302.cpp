#include <iostream>
using namespace std;

int main()
{
    int a[500]={},b[500]={},temp[500]={},res[500]={};
    int am=0,bm=0,d,max,cut=0,m;
    string s;
    while (getline(cin,s))
    {
        int n=s.length();
        int i=0;
        while (s[i]!=32)
            temp[am++]=s[i++]-48;
        i-=1;
        for (int ii=0;ii<am;ii++)
            a[ii]=temp[i--];
        i=am+1;
        d=s[i];
        for (i=i+2;i<n;i++)
            temp[bm++]=s[i]-48;
        i=bm-1;
        for (int ii=0;ii<bm;ii++)
            b[ii]=temp[i--];
        if (d==43)
        {
            max=(am>bm)?am:bm;
            for (int ii=0;ii<max;ii++)
            {
                res[ii]+=a[ii]+b[ii];
                if (res[ii]>=10)
                {
                    res[ii]%=10;
                    res[ii+1]++;
                }
                a[ii]=0;
                b[ii]=0;
            }
            if (res[max]!=0)
            {
                cout<<res[max];
                res[max]=0;
            }
            for (int ii=max-1;ii>=0;ii--)
            {
                cout<<res[ii];
                res[ii]=0;
            }
        }
        else if (d==45)
        {
            if (bm>am)
                cut=1;
            else if (am>bm)
                cut=0;
            else
            {
                for (int ii=am-1;ii>=0;ii--)
                {
                    if (b[ii]>a[ii])
                    {
                        cut=1;
                        break;
                    }
                    else if (a[ii]>b[ii])
                        break;
                }
            }
            if (cut==1)
            {
                cut=0;
                for (int ii=0;ii<bm;ii++)
                {
                    res[ii]=b[ii];
                    b[ii]=0;
                }
                for (int ii=0;ii<am;ii++)
                {
                    if (a[ii]>res[ii])
                    {
                        res[ii]=res[ii]-a[ii]+10;
                        res[ii+1]--;
                        a[ii]=0;
                    }
                    else
                    {
                        res[ii]-=a[ii];
                        a[ii]=0;
                    }
                }
                cout<<"-";
                for (i=bm-1;i>=0;i--)
                    if (res[i]!=0)
                    {
                        cout<<res[i];
                        res[i]=0;
                        break;
                    }
                i-=1;
                for (;i>=0;i--)
                {
                    cout<<res[i];
                    res[i]=0;
                }
            }
            else
            {
                for (int ii=0;ii<am;ii++)
                {
                    res[ii]=a[ii];
                    a[ii]=0;
                }
                for (int ii=0;ii<bm;ii++)
                {
                    if (b[ii]>res[ii])
                    {
                        res[ii]=res[ii]-b[ii]+10;
                        res[ii+1]--;
                        b[ii]=0;
                    }
                    else
                    {
                        res[ii]-=b[ii];
                        b[ii]=0;
                    }
                }
                for (i=am-1;i>=0;i--)
                    if (res[i]!=0)
                    {
                        cout<<res[i];
                        res[i]=0;
                        break;
                    }
                if (i==-1)
                    cout<<"0";
                i-=1;
                for (;i>=0;i--)
                {
                    cout<<res[i];
                    res[i]=0;
                }
            }
        }
        else if (d==42)
        {
            for (int ia=0;ia<am;ia++)
            {
                for (int ib=0;ib<bm;ib++)
                {
                    res[ia+ib]+=a[ia]*b[ib];
                    if (res[ia+ib]>=10)
                    {
                        res[ia+ib+1]+=res[ia+ib]/10;
                        res[ia+ib]%=10;
                    }
                }
            }
            for (int ii=0;ii<am;ii++)
                a[ii]=0;
            for (int ii=0;ii<bm;ii++)
                b[ii]=0;
            for (i=am+bm-1;i>=0;i--)
            if (res[i]!=0)
            {
                cout<<res[i];
                res[i]=0;
                break;
            }
            if (i==-1)
                cout<<"0";
            i-=1;
            for (;i>=0;i--)
            {
                cout<<res[i];
                res[i]=0;
            }
        }
        if (d==47)
        {
            if (bm>am)
                cout<<"0";
            else
            {
                for (i=am-1;i>=0;i--)
                {
                    if (b[i]>a[i])
                    {
                        cout<<"0";
                        break;
                    }
                    else if (a[i]>b[i])
                    {
                        cut=1;
                        break;
                    }
                }
                if (i==-1)
                    cout<<"1";
                else if (cut==1)
                {
                    cut=0;
                    for (int ii=0;ii<=am;ii++)
                        temp[ii]=0;
                    for (int ii=am-bm;ii>=0;ii--)
                    {
                        for (int iii=0;iii<bm;iii++)
                        {
                            m=1;
                            temp[ii+iii]+=b[iii]*9;
                            if (temp[ii+iii]>=10)
                            {
                                temp[ii+iii+1]+=temp[ii+iii]/10;
                                temp[ii+iii]%=10;
                                while (temp[ii+iii+m]>=10)
                                {
                                    temp[ii+iii+m+1]+=temp[ii+iii+m]/10;
                                    temp[ii+iii+m]%=10;
                                    m++;
                                }
                            }
                        }
                        res[ii]=9;
                        for (i=am;i>=0;i--)
                        {
                            if (a[i]>temp[i])
                                break;
                            else if (a[i]<temp[i])
                            {
                                for (int iii=0;iii<bm;iii++)
                                {
                                    m=1;
                                    temp[ii+iii]-=b[iii];
                                    if (temp[ii+iii]<0)
                                    {
                                        temp[ii+iii]+=10;
                                        temp[ii+iii+1]--;
                                        while (temp[ii+iii+m]<0)
                                        {
                                            temp[ii+iii+m]+=10;
                                            temp[ii+iii+m+1]--;
                                            m++;
                                        }
                                    }
                                }
                                i=am+1;
                                res[ii]--;
                            }
                            else if (res[ii]==0)
                                break;
                        }
                    }
                }
                for (i=am-1;i>=0;i--)
                    if (res[i]!=0)
                    {
                        cout<<res[i];
                        res[i]=0;
                        break;
                    }
                i-=1;
                for (;i>=0;i--)
                {
                    cout<<res[i];
                    res[i]=0;
                }
                for (int ii=0;ii<am;ii++)
                    a[ii]=0;
                for (int ii=0;ii<bm;ii++)
                    b[ii]=0;
            }
        }
        cout<<endl;
        am=0;
        bm=0;
    }
    //system("pause");
    return 0;
}
