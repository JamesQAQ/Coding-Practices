#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char s[10000];
    int num[10001];
    while (scanf("%s",&s))
    {
        int len=strlen(s);
        if (len==1&&s[0]=='0')
            break;
        num[len]=1;
        num[len-1]=(s[len-1]=='0')?0:1;
        for (int i=len-2;i>=0;i--)
        {
            if (s[i]=='0')
                num[i]=0;
            else if ((s[i]-48)*10+s[i+1]-48<=26&&(s[i]-48)*10+s[i+1]-48>=10)
                num[i]=num[i+1]+num[i+2];
            else
                num[i]=num[i+1];    
        }
        printf("%d\n",num[0]);
    }
    return 0;
}
