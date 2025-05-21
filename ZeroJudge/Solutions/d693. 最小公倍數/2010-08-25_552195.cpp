#include <iostream>
using namespace std;

int test(int a[],int n)
{
    for (int i=0;i<n;i++)
        if (a[i]!=1)
            return 1;
    return 0;
}
int main()
{
    int n,ans,a[10],num[25],p[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0)
            break;
        memset(num,0,sizeof(num));
        ans=1;
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        stable_sort(a,a+n);
        int c=0;
        while (test(a,n))
        {
            bool real=0;
            for (int i=0;i<n;i++)
                if (a[i]%p[c]==0)
                {
                    a[i]/=p[c];
                    real=1;
                }
            if (real)
                num[c]++;
            else
                c++;
        }
        for (int i=0;i<25;i++)
            for (int j=0;j<num[i];j++)
                ans*=p[i];
        printf("%d\n",ans);
    }
    //system("pause");
    return 0;
}
