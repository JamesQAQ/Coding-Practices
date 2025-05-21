#include <iostream>
using namespace std;

int main()
{
    bool ok[100001]={};
    int a[100001];
    a[0]=0;
    for (int i=1;i*i<100001;i++)
        ok[i*i]=1;
    for (int i=1;i<100001;i++)
    {
        a[i]=a[i-1];
        if (ok[i])
            a[i]++;
    }
    int b,c;
    while (scanf("%d",&b))
    {
        scanf("%d",&c);
        if (b==0&&c==0)
            break;
        printf("%d\n",((ok[b])?a[c]-a[b]+1:a[c]-a[b]));
    }
    return 0;
}
