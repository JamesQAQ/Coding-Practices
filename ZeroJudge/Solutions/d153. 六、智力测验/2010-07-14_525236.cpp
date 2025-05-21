#include <iostream>
#include <stdio.h>
using namespace std;

int a[40000];
int main()
{
	int t,n;
	while (scanf("%d",&t)!=EOF)
	{
		for (int j=0;j<t;j++)
		{
			scanf("%d",&n);
			for (int i=0;i<n;i++)
				scanf("%d",&a[i]);
			sort(a,a+n);
			if (n%2==1)
				printf("%d\n",a[(n-1)/2]);
			else
				printf("%d\n",a[n/2-1]);
		}
	}
	//system("pause");
	return 0;
}
