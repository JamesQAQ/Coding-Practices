#include <iostream>
#include <stdio.h>
using namespace std;

int maxsum(int b[],int n)
{
	int sum=0,max=b[0];
	for (int i=0;i<n;i++)
	{
		if (sum>=0)
			sum=b[i];
		else
			sum+=b[i];
		if (sum<max)
			max=sum;
	}
	return max;
}

int main()
{
	int n,a[100][100],b[100]={},max,sum;
	while (scanf("%d",&n)!=EOF)
	{
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		max=a[0][0];
		for (int i=0;i<n;i++)
		{
			memset(b,0,sizeof(b));
			for (int j=i;j<n;j++)
			{
				for (int k=0;k<n;k++)
					b[k]+=a[j][k];
				if ((sum=maxsum(b,n))<max)
					max=sum;
			}
		}
		printf("%d\n",max);
	}
   //system("pause");
   return 0;
}
