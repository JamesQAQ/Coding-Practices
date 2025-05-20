#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int m,n,map[100][100],sum[100][100],ansi,ansj,mini;
	while (cin>>m>>n)
	{
		mini=-1;
		for (int i=0;i<m;i++)
			for (int j=0;j<n;j++)
			{
				sum[i][j]=0;
				cin>>map[i][j];
			}
		for (int i=0;i<m;i++)
			for (int j=0;j<n;j++)
			{
				for (int k=0;k<m;k++)
					for (int l=0;l<n;l++)
						sum[i][j]+=(abs(i-k)+abs(j-l))*map[k][l];
				if (mini==-1||sum[i][j]<mini)
				{
					mini=sum[i][j];
					ansi=i;
					ansj=j;
				}
			}
		cout<<ansi+1<<" "<<ansj+1<<endl;
	}
}
