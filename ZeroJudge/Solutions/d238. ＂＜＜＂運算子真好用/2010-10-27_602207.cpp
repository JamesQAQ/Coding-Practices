#include<iostream>
using namespace std;

short a[1001][500]={};
int main()
{
	a[0][0]=1;
	for (int i=1;i<=1000;i++)
	{
		for (int j=0;j<500;j++)
		{
			a[i][j]+=a[i-1][j]*2;
			if (a[i][j]>=10)
			{
				a[i][j+1]+=a[i][j]/10;
				a[i][j]%=10;
			}
		}
	}
	int sum=0;
	for (int i=0;i<500;i++)
		sum+=a[1000][i];
	cout<<sum<<endl;
	return 0;
}
