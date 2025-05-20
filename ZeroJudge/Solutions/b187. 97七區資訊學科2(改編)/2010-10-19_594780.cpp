#include <iostream>
using namespace std;

int main()
{
    puts("十六進位表示法  相對應的十進位表示法");
    char a,b;
    while (cin>>a>>b)
    {
        printf("      %c%c                 ",a,b);
        int sum=0;
        if (a<='F'&&a>='A')
            sum+=(a-'A'+10)*16;
        else
            sum+=(a-48)*16;
        if (b<='F'&&b>='A')
            sum+=(b-'A'+10);
        else
            sum+=(b-48);
        printf("%d\n",sum);
    }
    return 0;
}
