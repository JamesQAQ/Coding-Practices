#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,i=0;
    while (scanf("%d",&n))
    {
        if (n==0)
            break;
        i++;
        printf("Test Case %d:\n",i);
        bool sclass[n][256];
        memset(sclass,0,sizeof(sclass));
        char s[257]={};
        for (int i=0;i<n;i++)
        {
            scanf("%s",&s);
            int len=strlen(s);
            for (int j=0;j<len;j++)
                sclass[i][s[j]]=1;
        }
        for (int i=0;i<n;i++)   
            for (int j=i+1;j<n;j++)
            {
                int k;
                printf("%c: {",i+'A');
                for (k=0;k<256;k++)
                    if (sclass[i][k])
                        printf("%c",k);
                puts("}");
                printf("%c: {",j+'A');
                for (k=0;k<256;k++)
                    if (sclass[j][k])
                        printf("%c",k);
                puts("}");
                printf("%c+%c: {",i+'A',j+'A');
                for (k=0;k<256;k++)
                    if (sclass[i][k]||sclass[j][k])
                        printf("%c",k);
                puts("}");
                printf("%c*%c: {",i+'A',j+'A');
                for (k=0;k<256;k++)
                    if (sclass[i][k]&&sclass[j][k])
                        printf("%c",k);
                puts("}");
                printf("%c-%c: {",i+'A',j+'A');
                for (k=0;k<256;k++)
                    if (sclass[i][k]&&!sclass[j][k])
                        printf("%c",k);
                puts("}");
                printf("%c-%c: {",j+'A',i+'A');
                for (k=0;k<256;k++)
                    if (sclass[j][k]&&!sclass[i][k])
                        printf("%c",k);
                puts("}");
                for (k=0;k<256;k++)
                    if (sclass[j][k]&&!sclass[i][k])
                        break;
                if (k==256)
                    printf("%c contains %c\n",i+'A',j+'A');
                else
                    printf("%c does not contain %c\n",i+'A',j+'A');
                for (k=0;k<256;k++)
                    if (sclass[i][k]&&!sclass[j][k])
                        break;
                if (k==256)
                    printf("%c contains %c\n",j+'A',i+'A');
                else
                    printf("%c does not contain %c\n",j+'A',i+'A');
            }
    }
    return 0;
}
