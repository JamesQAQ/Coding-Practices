#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    char str[1000];
    int cnt=1;
    while(scanf("%s",&str)!=EOF)
    {
        printf("AB Circle #%d:\n",cnt);
        cnt++;
        int l=strlen(str),_tmp,ta=0,tb=0;
        for(int i=0;i<l;++i)
            if(str[i]=='a')
                ++ta;
        tb=l-ta;
        _tmp=ta;
        ta=min(ta,tb);
        tb=max(_tmp,tb);
        if(ta==tb)
            for(int i=0;i<l-ta;++i)
                printf("%d,%d\n",i,i+ta);
        else{
            for(int i=0;i<l-tb;++i)
                printf("%d,%d\n%d,%d\n",i,i+ta,i,i+tb);
            for(int i=l-tb;i<l-ta;++i)
                printf("%d,%d\n",i,i+ta);
        }
    }
    return 0;
}
