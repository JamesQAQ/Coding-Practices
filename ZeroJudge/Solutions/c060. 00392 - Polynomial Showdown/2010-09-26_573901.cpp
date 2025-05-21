#include <iostream>
#include <stdio.h>
#include <sstream>
using namespace std;

int main()
{
    int num[10];
    string s;
    while (getline(cin,s))
    {
        stringstream ss(s);
        int d=0;
        while (ss>>num[d])
            d++;
        int start,end;
        for (start=0;start<9;start++)
            if (num[start]!=0)
                break;
        if (start==9)
        {
            puts("0");
            continue;
        }
        for (end=8;end>=0;end--)
            if (num[end]!=0)
                break;
        if (num[start]!=1&&num[start]!=-1)
            printf("%d",num[start]);
        if (num[start]==-1)
            printf("-");
        if (start!=8)
            printf("x");
        if (start!=7&&start!=8)
            printf("^%d",8-start);
        for (int i=start+1;i<end;i++)
        {
            if (num[i]!=0)
            {
                if (num[i]<0)
                {
                    printf(" - ");
                    num[i]=-num[i];
                }
                else
                    printf(" + ");
                if (num[i]!=1)
                    printf("%d",num[i]);
                if (i!=7)
                    printf("x^%d",8-i);
                else
                    printf("x");
            }
        }
        if (start!=end)
        {
            if (num[end]<0)
            {
                printf(" - ");
                num[end]=-num[end];
            }
            else
                printf(" + ");
            if (end!=8)
            {
                if (num[end]!=1)
                    printf("%d",num[end]);
                if (end!=7)
                    printf("x^%d",8-end);
                else
                    printf("x");
            }
            else
                printf("%d",num[end]);
        }
        printf("\n");
    }
    return 0;
}
