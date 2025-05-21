#include<iostream>
using namespace std;

int map[100][100],n,k;
long long int sum[100][100];
bool use[100][100];
void test (int x,int y)
{
	use[x][y]=1;
	for (int i=1;i<=k;i++)
	{
		if (x+i<n&&map[x+i][y]<map[x][y])
		{
			if (!use[x+i][y])
				test(x+i,y);
			if (sum[x+i][y]+map[x][y]>sum[x][y])
				sum[x][y]=sum[x+i][y]+map[x][y];
		}
		if (y+i<n&&map[x][y+i]<map[x][y])
		{
			if (!use[x][y+i])
				test(x,y+i);
			if (sum[x][y+i]+map[x][y]>sum[x][y])
				sum[x][y]=sum[x][y+i]+map[x][y];
		}
		if (x-i>=0&&map[x-i][y]<map[x][y])
		{
			if (!use[x-i][y])
				test(x-i,y);
			if (sum[x-i][y]+map[x][y]>sum[x][y])
				sum[x][y]=sum[x-i][y]+map[x][y];
		}
		if (y-i>=0&&map[x][y-i]<map[x][y])
		{
			if (!use[x][y-i])
				test(x,y-i);
			if (sum[x][y-i]+map[x][y]>sum[x][y])
				sum[x][y]=sum[x][y-i]+map[x][y];
		}
	}
}
int main()
{
	while (scanf("%d",&n)!=EOF)
	{
		long long int ans=-10000000;
		scanf("%d",&k);
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				scanf("%d",&map[i][j]);
				use[i][j]=0;
				sum[i][j]=-10000000;
			}
		use[0][0]=1;
		sum[0][0]=map[0][0];
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				if (!use[i][j])
					test(i,j);
				if (sum[i][j]>ans)
					ans=sum[i][j];
			}
		cout<<ans<<endl;
	}
	return 0;
}
