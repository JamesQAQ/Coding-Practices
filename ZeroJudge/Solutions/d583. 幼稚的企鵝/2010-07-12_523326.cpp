#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n,a;
	while (scanf("%d",&n)!=EOF)
	{
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			printf("%d ",i);
		}
		printf("\n");
	}
   //system("pause");
   return 0;
}
