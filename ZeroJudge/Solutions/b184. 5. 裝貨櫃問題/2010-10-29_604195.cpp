#include <iostream>
using namespace std;

int c[10001][101],v[10001],p[10001];
int main()
{
	int n;
	while (cin>>n)
	{
		for (int i=1;i<=n;i++)
			cin>>v[i]>>p[i];
		c[0][0]=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=100;j++)
			{
				if (v[i]<=j)
				{
					if (p[i]+c[i-1][j-v[i]]>c[i-1][j])
						c[i][j]=p[i]+c[i-1][j-v[i]];
					else
						c[i][j]=c[i-1][j];
				}
				else
					c[i][j]=c[i-1][j];
			}
		cout<<c[n][100]<<endl;
	}
}
