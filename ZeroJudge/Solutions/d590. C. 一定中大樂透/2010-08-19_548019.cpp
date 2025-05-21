#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a,b;
    while (scanf("%d",&a)!=EOF)
    {
        scanf("%d",&b);
        if ((a==0)&&(b==0))
            break;
        if ((a%2==b%2))
            printf("Win\n");
        else
            printf("Loss\n");
    }
    //system ("pause");
    return 0;
}
