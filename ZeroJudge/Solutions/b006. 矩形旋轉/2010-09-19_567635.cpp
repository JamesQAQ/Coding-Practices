#include <iostream>
#include <stdio.h>
using namespace std;

int a[1000][2];
bool cmp(int i,int j)
{
    if (a[i][0]*a[i][1]<a[j][0]*a[j][1]) return 1;
    if (a[i][0]*a[i][1]>a[j][0]*a[j][1]) return 0;
    return 0;
}
int main()
{
    int n,sum[1000],temp,t[1000],max;
    while (scanf("%d",&n)!=EOF)
    {
        max=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i][0]);
            scanf("%d",&a[i][1]);
            if (a[i][1]>a[i][0])
            {
                temp=a[i][1];
                a[i][1]=a[i][0];
                a[i][0]=temp;
            }
            sum[i]=1;
            t[i]=i;
        }
        stable_sort(t,t+n,cmp);
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<i;j++)
            {
                if ((a[t[j]][0]<=a[t[i]][0])&&(a[t[j]][1]<=a[t[i]][1]))
                    if (sum[t[j]]>=sum[t[i]])
                        sum[t[i]]=sum[t[j]]+1;
            }
            if (sum[t[i]]>max)
                max=sum[t[i]];
        }
        printf("%d\n",max);
    }
    return 0;
}
