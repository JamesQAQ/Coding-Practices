#include <iostream>
#include <stdio.h>
using namespace std;

string s;
int test(int p)
{
    if (s[p]=='P')
        return 1;
    else
    {
        if (s[p+1]=='c')
            return 2;
        else
            return 3;
    }
}
int main()
{
    int a,b,an=0,bn=0;
    while (getline(cin,s))
    {
        int n=s.length();
        if (s[0]=='G')
        {
            if (bn>an)
                printf("悲慘的籌措起香油錢\n");
            else
                printf("螢火的蹤跡\n");
            an=0;
            bn=0;
            continue;
        }
        else
        {
            a=test(0);
            int p=s.find(" ");
            p++;
            b=test(p);
            if (a==1)
            {
                if (b==2)
                {
                    printf("靈夢獲勝\n");
                    bn++;
                }
                else
                {
                    printf("紫獲勝\n");
                    an++;
                }
            }
            else if(a==2)
            {
                if (b==3)
                {
                    printf("靈夢獲勝\n");
                    bn++;
                }
                else
                {
                    printf("紫獲勝\n");
                    an++;
                }
            }
            else
            {
                if (b==1)
                {
                    printf("靈夢獲勝\n");
                    bn++;
                }
                else
                {
                    printf("紫獲勝\n");
                    an++;
                }
            }
        }
    }    
    return 0;
}
