#include<iostream>
#include<algorithm>
using namespace std;

int a[10000][200],n,m;
bool cmp (int i,int j)
{
	for (int k=0;k<m;k++)
	{
		if (a[i][k]<a[j][k])
			return 1;
		if (a[i][k]>a[j][k])
			return 0;
	}
	return 1;
}
int main()
{
	int t[10000];
	while (cin>>n>>m)
	{
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
				scanf("%d",&a[i][j]);
			t[i]=i;
		}
		stable_sort(t,t+n,cmp);
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
				printf("%d ",a[t[i]][j]);
			printf("\n");
		}
	}
	return 0;

}
