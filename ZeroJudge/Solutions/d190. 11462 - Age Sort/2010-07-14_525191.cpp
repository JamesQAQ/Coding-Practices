#include <iostream>
#include <stdio.h>
using namespace std;

int a[2000000];
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		if (n==0)
			break;
		for (int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		for (int i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	//system("pause");
	return 0;
}
