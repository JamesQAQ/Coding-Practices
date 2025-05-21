#include <iostream>
using namespace std;

int hash(char s[])
{
    int len=strlen(s),x=0;
    for (int i=0;i<len;i++)
    {
        x=x*26+s[i]-'a';
        x%=10000;
    }
    return x;
}
int main()
{
    int n,t,at[10000];
    char s2[30];
    string dic[10000],s;
    while (scanf("%d",&n)!=EOF)
    {
        bool use[10000]={};
        t=1;
        for (int i=0;i<n;i++)
        {
            scanf("%s",s2);
            int x=hash(s2);
            if (use[x])
            {
                while (use[x]&&s2!=dic[x])
                {
                    x++;
                    x%=10000;
                }
                if (use[x])
                    printf("Old! %d\n",at[x]);
                else
                {
                    use[x]=1;
                    at[x]=t++;
                    dic[x]=s2;
                    printf("New! %d\n",at[x]);
                }
            }
            else
            {
                use[x]=1;
                at[x]=t++;
                dic[x]=s2;
                printf("New! %d\n",at[x]);
            }
        }
    }
    return 0;
}
