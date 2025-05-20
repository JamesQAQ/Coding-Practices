#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,a,b;
    char ans[5],in[5];
    while (cin>>ans)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            a=0;
            b=0;
            cin>>in;
            for (int i=0;i<4;i++)
                for (int j=0;j<4;j++)
                    if (in[i]==ans[j])
                    {
                        if (i==j)
                            a++;
                        else
                            b++;
                        break;
                    }
            printf("%dA%dB\n",a,b);
        }
    }
    return 0;
}
