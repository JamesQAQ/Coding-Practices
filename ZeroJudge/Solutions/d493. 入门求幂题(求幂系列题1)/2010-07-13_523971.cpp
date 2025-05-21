#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    long long int r=1;
    int a,n;
    while (scanf("%d",&a)!=EOF)
    {
		  scanf("%d",&n);
		  if (a==1)
		      printf("1\n");
		  else if (a==-1)
		  {
				if (n%2==0)
					printf("1\n");
				else
					printf("-1\n");
		  }
		  else if (a==0)
		  		printf("0\n");
		  else
		  {
        	   for (int i=0;i<n;i++)
                r*=a;
        	   printf("%d\n",r);
            r=1;
		  }
    }
    //system("pause");
    return 0;
}
