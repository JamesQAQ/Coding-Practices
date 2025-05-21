#include <iostream>
using namespace std;

int main()
{
    char s[500],k[500];
    int a=0;
    while (gets(s))
    {
        int n=strlen(s);
        if (!strcmp(s,"0"))
            break;
        while (1)
        {
            gets(k);
            if (!strcmp(k,"0"))
                break;
            a+=k[strlen(k)-1]-48;
            a%=10;
        }
        if (a!=s[strlen(s)-1]-48)
            puts("0");
        else
        {
            if (a%2==1)
                puts("2");
            else
                puts("1");
        }
        a=0;
    }
    //system("pause");
    return 0;
}
