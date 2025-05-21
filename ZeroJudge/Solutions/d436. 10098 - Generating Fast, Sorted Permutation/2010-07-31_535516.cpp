#include <iostream>
#include <stdio.h>
using namespace std;

int len,leno;
char s[10],ans[10];
int k[10];
void paint(int d)
{
    if (d==leno)
    {
        for (int i=0;i<leno;i++)
            printf("%c",ans[i]);
        printf("\n");
    }
    else
    {
        for (int i=0;i<len;i++)
            if (k[i])
            {
                ans[d]=s[i];
                k[i]--;
                paint(d+1);
                k[i]++;
            }
    }
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            cin>>s;
            len=strlen(s);
            leno=len;
            sort(s,s+len);
            memset(k,0,sizeof(k));
            for (int j=0;j<len;j++)
            {
                k[j]++;
                while (s[j+1]==s[j])
                {
                    k[j]++;
                    for (int y=j;y<len;y++)
                        s[y+1]=s[y+2];
                    len--;
                }
            }
            paint(0);
            printf("\n");
        }
    }
    //system ("pause");
    return 0;
}
