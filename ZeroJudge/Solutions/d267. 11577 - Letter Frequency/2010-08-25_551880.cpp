#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,a[26],max;
    string s;
    while (scanf("%d",&n)!=EOF)
    {
        getline(cin,s);
        for (int i=0;i<n;i++)
        {
            getline(cin,s);
            memset(a,0,sizeof(a));
            max=0;
            int l=s.length();
            for (int j=0;j<l;j++)
            {
                if ((s[j]>=65)&&(s[j]<=90))
                    a[s[j]-65]++;
                else if ((s[j]>=97)&&(s[j]<=122))
                    a[s[j]-97]++;
            }
            for (int j=0;j<26;j++)
                if (a[j]>max)
                    max=a[j];
            for (int j=0;j<26;j++)
                if (a[j]==max)
                    printf("%c",j+97);
            printf("\n");
        }
    }
    //system ("pause");
    return 0;
}
