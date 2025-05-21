#include <iostream>
#include <stdio.h>
using namespace std;
#define len 3000

int a[1001][len]={};
int main()
{
	int n;
	a[1][0]=1;
	for (int i=2;i<1001;i++)
	{
		for (int j=0;j<len;j++)
		{
			a[i][j]+=a[i-1][j]*i;
			a[i][j+2]+=a[i][j]/100;
			a[i][j]%=100;
			a[i][j+1]+=a[i][j]/10;
			a[i][j]%=10;
		}
	}
	while (scanf("%d",&n)!=EOF)
	{
		printf("%d!\n",n);
		int y;
		for (y=len-1;y>=0;y--)
			if (a[n][y]!=0)
			{
				printf("%d",a[n][y]);
				break;
			}
		y--;
		for (;y>=0;y--)
			printf("%d",a[n][y]);
		printf("\n");
	}
	//system("pause");
	return 0;
}
