#include <iostream>
#include <stdio.h>
using namespace std;

int n,w=0,c=1,sum=0,amount[10000000];
char word[10000000],word_c[10000000];
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        word[0]=getchar();
        word[0]=getchar();
        word_c[w]=word[0];
        for (int i=1;i<n;i++)
        {
            word[i]=getchar();
            if (word[i]!=word[i-1])
            {
                amount[w]=c;
                if (c<10)
                    sum+=2;
                else if (c<100)
                    sum+=3;
                else if (c<1000)
                    sum+=4;
                else if (c<10000)
                    sum+=5;
                else if (c<100000)
                    sum+=6;
                else if (c<1000000)
                    sum+=7;
                else 
                	  sum+=8;
                c=1;
                w++;
                word_c[w]=word[i];
            }
            else
                c++;
        }
        amount[w]=c;
        if (c<10)
            sum+=2;
        else if (c<100)
            sum+=3;
        else if (c<1000)
            sum+=4;
        else if (c<10000)
            sum+=5;
        else if (c<100000)
            sum+=6;
        else if (c<1000000)
            sum+=7;
        else
        	   sum+=8;
        c=1;
        w++;
        if (sum>=n)
        {
            for (int i=0;i<w;i++)
            	 for (int j=0;j<amount[i];j++)
                    printf("%c",word_c[i]);
        }
        else
        {
            for (int i=0;i<w;i++)
            {
                printf("%d",amount[i]);
                printf("%c",word_c[i]);
            }
        }
        printf("\n");
        w=0;
        sum=0;
    }
    //system("pause");
    return 0;
}
