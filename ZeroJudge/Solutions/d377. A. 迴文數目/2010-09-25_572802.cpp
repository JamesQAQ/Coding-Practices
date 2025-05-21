#include <iostream>
#include <stdio.h>
using namespace std;

long long int allnum,allsum,N[21];
void Init()
{
    int i;
    N[0]=1;
    for (i=1; i<21; i++)
        N[i]=N[i-1]*i;
}
bool g(int num[])
{
    int sum=0;
    for (int i=0;i<26;i++)
    {
        if (num[i]%2==1)
        {
            sum++;
            num[i]--;
        }
        num[i]/=2;
        allnum+=num[i];
    }
    if (sum>1)
        return 1;
    return 0;
}
int main()
{
    Init();
    int n;
    char s[41];
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            allnum=0;
            int num[26]={};
            scanf("%s",&s);
            int len=strlen(s);
            for (int j=0;j<len;j++)
                num[s[j]-'a']++;
            if (g(num))
            {
                puts("0");
                continue;
            }
            allsum=N[allnum];
            for (int i=0;i<26;i++)
                allsum/=N[num[i]];
            printf("%lld\n",allsum);
        }
    }   
    return 0;
}
