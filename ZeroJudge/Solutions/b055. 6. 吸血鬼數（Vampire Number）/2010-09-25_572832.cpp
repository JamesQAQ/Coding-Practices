#include <iostream>
#include <stdio.h>
using namespace std;

bool cmp4(int i,int j,int vt)
{
    int a[4],b[4];
    a[0]=i/10; a[1]=i%10; a[2]=j/10; a[3]=j%10;
    b[0]=vt/1000; vt%=1000; b[1]=vt/100; vt%=100;
    b[2]=vt/10; b[3]=vt%10;
    sort(a,a+4); sort(b,b+4);
    for (int k=0;k<4;k++)
        if (a[k]!=b[k])
            return 0;
    return 1;
}
bool cmp6(int i,int j,int vt)
{
    int a[6],b[6];
    a[0]=i/100; i%=100; a[1]=i/10; a[2]=i%10;
    a[3]=j/100; j%=100; a[4]=j/10; a[5]=j%10;
    b[0]=vt/100000; vt%=100000; b[1]=vt/10000; vt%=10000;
    b[2]=vt/1000; vt%=1000; b[3]=vt/100; vt%=100;
    b[4]=vt/10; b[5]=vt%10;
    sort(a,a+6); sort(b,b+6);
    for (int k=0;k<6;k++)
        if (a[k]!=b[k])
            return 0;
    return 1;
}
bool cmp8(int i,int j,int vt)
{
    int a[8],b[8];
    a[0]=i/1000; i%=1000; a[1]=i/100; i%=100; a[2]=i/10; a[3]=i%10;
    a[4]=j/1000; j%=1000; a[5]=j/100; j%=100; a[6]=j/10; a[7]=j%10;
    b[0]=vt/10000000; vt%=10000000; b[1]=vt/1000000; vt%=1000000;
    b[2]=vt/100000; vt%=100000; b[3]=vt/10000; vt%=10000;
    b[4]=vt/1000; vt%=1000; b[5]=vt/100; vt%=100;
    b[6]=vt/10; b[7]=vt%10;
    sort(a,a+8); sort(b,b+8);
    for (int k=0;k<8;k++)
        if (a[k]!=b[k])
            return 0;
    return 1;
}
bool repeat(int ans[],int num,int vt)
{
    for (int i=0;i<num;i++)
        if (ans[i]==vt)
            return 0;
    return 1;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int ans[10000],num=0;
        if (n==4)
        {
            for (int i=10;i<100;i++)
                for (int j=i;j<100;j++)
                {
                    int vt=i*j;
                    if (vt<10000&&vt>=1000)
                        if (vt%2==0)
                            if (!(i%10==0&&j%10==0))
                                if (cmp4(i,j,vt))
                                    if (repeat(ans,num,vt))
                                    {
                                        ans[num]=vt;
                                        num++;
                                    }
                }
        }
        else if (n==6)
        {
            for (int i=100;i<1000;i++)
                for (int j=i;j<1000;j++)
                {
                    int vt=i*j;
                    if (vt<1000000&&vt>=100000)
                        if (vt%2==0)
                            if (!(i%10==0&&j%10==0))
                                if (cmp6(i,j,vt))
                                    if (repeat(ans,num,vt))
                                    {
                                        ans[num]=vt;
                                        num++;
                                    }
                }
        }
        else if (n==8)
        {
            for (int i=1000;i<10000;i++)
                for (int j=i;j<10000;j++)
                {
                    int vt=i*j;
                    if (vt<100000000&&vt>=10000000)
                        if (vt%2==0)
                            if (!(i%10==0&&j%10==0))
                                if (cmp8(i,j,vt))
                                    if (repeat(ans,num,vt))
                                    {
                                        ans[num]=vt;
                                        num++;
                                    }
                }
        }
        sort(ans,ans+num);
        for (int i=0;i<num;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
