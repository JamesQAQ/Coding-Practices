#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0)
            break;
        int j=n-1,k=1;
        for (int i=0;i<n;i++)
        {
            for (int l=0;l<j;l++)
                printf("_");
            j--;
            for (int l=0;l<k;l++)
                printf("+");
            k++;
            printf("\n");
        }
    }
    //system("pause");
    return 0;
}
