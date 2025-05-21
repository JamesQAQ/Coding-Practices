#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    long long int r=1;
    int a,n,ii=1;
    while (scanf("%d",&a)!=EOF)
    {
		  scanf("%d",&n);
		  if ((a==0)&&(n==0))
		  {
				printf("All Over. Exceeded 65536 lines!\n");
				ii=1;
				break;
		  }
		  else if (a==1)
		  {
		      printf("1\n");
		      ii++;
		  }
		  else if (a==-1)
		  {
				if (n%2==0)
					printf("1\n");
				else
					printf("-1\n");
				ii++;
		  }
		  else if (a==0)
		  {
		  		printf("0\n");
		  		ii++;
		  }
		  else
		  {
        	   for (int i=0;i<n;i++)
                r*=a;
        	   printf("%d\n",r);
            r=1;
            ii++;
		  }
    }
    //system("pause");
    return 0;
}
