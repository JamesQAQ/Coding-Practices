#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int nn=sqrt(n);
        while (nn*(nn+1)/2<n)
            nn++;
        nn--;
        if (nn%2==1)
            printf("TERM %d IS %d/%d\n",n,n-nn*(nn+1)/2,nn+2-(n-nn*(nn+1)/2));
        else
            printf("TERM %d IS %d/%d\n",n,nn+2-(n-nn*(nn+1)/2),n-nn*(nn+1)/2);
    }
    return 0;
}
