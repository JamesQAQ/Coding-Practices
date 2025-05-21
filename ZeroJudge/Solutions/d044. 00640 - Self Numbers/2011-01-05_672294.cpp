#include <iostream>
using namespace std;

int sod(int x)
{
    int sum=0;
    while (x!=0)
    {
        sum+=x%10;
        x/=10;
    }
    return sum;
}
int main()
{
    bool use[1000001];
    memset(use,1,sizeof(use));
    for (int i=1;i<=1000000;i++)
    {
        if (use[i])
            printf("%d\n",i);
        int x=i+sod(i);
        while (x<1000001&&use[x])
        {
            use[x]=0;
            x=x+sod(x);
        }
    }
    return 0;
}
