#include <iostream>
using namespace std;

int main()
{
    int n;
    bool nega,first;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0)
            break;
        if (n==1)
        {
            puts("1 = 1");
            continue;
        }
        printf("%d = ",n);
        nega=0;
        first=0;
        if (n<0)
        {
            n=-n;
            printf("-1");
            nega=1;
            first=1;
        }
        for (int i=2;i<=46340;i++)
            if (n%i==0)
            {
                while (n%i==0)
                {
                    if (nega)
                        printf(" x ");
                    else
                        nega=1;
                    first=1;
                    n/=i;
                    printf("%d",i);
                }
                if (n==1)
                    break;
            }
        if (n!=1)
        {
            if (first)
                printf(" x ");
            printf("%d",n);
        }
        puts("");
    }
    return 0;
}
