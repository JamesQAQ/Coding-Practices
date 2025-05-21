#include <iostream>
using namespace std;

int main()
{
    int n,d;
    bool ne;
    while (scanf("%d",&n)!=EOF)
    {
        d=1;
        ne=0;
        if (n<0)
        {
            ne=1;
            n=-n;
        }
        for (int i=2;i*i<=n;i++)
        {
            if (n==1)
                break;
            if (n%(i*i)==0)
                while (n%(i*i)==0)
                {
                    d*=i;
                    n/=i*i;
                }
        }
        if (n==0)
            printf("0");
        else if (d==1&&n==1&&!ne)
            printf("1");
        else if (d!=1)
        {
            printf("%d",d);
            if (n!=1)
                printf("_/%d",n);
        }
        else if (n!=1)
        {
            if (d!=1)
                printf("%d",d);
            printf("_/%d",n);
        }
        if (ne)
            printf("i");
        printf("\n");
    }
    return 0;
}
