#include <iostream>
using namespace std;

int main()
{
    int n,a[1000],b[1000],numa[10],numb[10],A,B,t=0;
    while (cin>>n)
    {
        if (n==0)
            break;
        memset(numa,0,sizeof(numa));
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
            numa[a[i]]++;
        }
        printf("Game %d:\n",++t);
        while (1)
        {
            int temp[10];
            for (int i=0;i<10;i++)
                temp[i]=numa[i];
            memset(numb,0,sizeof(numb));
            for (int i=0;i<n;i++)
            {
                cin>>b[i];
                numb[b[i]]++;
            }
            if (numb[0]==n)
                break;
            A=0;
            B=0;
            for (int i=0;i<n;i++)
                if (a[i]==b[i])
                {
                    A++;
                    temp[a[i]]--;
                    numb[b[i]]--;
                }
            for (int i=1;i<10;i++)
                B+=min(temp[i],numb[i]);
            printf("    (%d,%d)\n",A,B);
        }
    }
    return 0;
}
