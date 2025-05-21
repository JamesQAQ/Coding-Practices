#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    string s;
    bool ans[5];
    while (getline(cin,s))
    {
        int n=s.length();
        int i;
        for (i=0;i<5;i++)
        {
            ans[i]=s[i]-48;
            printf("%c",s[i]);
        }
        i++;
        while (i<n)
        {
            if (s[i]=='o')
            {
                printf("||");
                i+=3;
                for (int j=0;j<5;j++)
                {
                    printf("%c",s[i]);
                    ans[j]=(ans[j]||(s[i]-48));
                    i++;
                }
            }
            else
            {
                printf("&&");
                i+=4;
                for (int j=0;j<5;j++)
                {
                    printf("%c",s[i]);
                    ans[j]=(ans[j]&&(s[i]-48));
                    i++;
                }
            }
            i++;
        }
        printf(" = ");
        for (int i=0;i<5;i++)
            printf("%d",ans[i]);
        printf("\n");
    }
    //system ("pause");
    return 0;
}
