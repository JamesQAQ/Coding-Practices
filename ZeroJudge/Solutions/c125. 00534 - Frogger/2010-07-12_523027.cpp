#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
	int n,xy[201][2],ii=1;
	double p[201][201];
	cout.setf(ios::fixed);
	cout.precision(3);
	while (scanf("%d",&n)!=EOF)
	{
		if (n==0)
			break;
		for (int i=1;i<=n;i++)
			scanf("%d%d",&xy[i][0],&xy[i][1]);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				p[i][j]=sqrt((xy[j][0]-xy[i][0])*(xy[j][0]-xy[i][0])+(xy[j][1]-xy[i][1])*(xy[j][1]-xy[i][1]));
		for (int x=1;x<=n;x++)
				for (int y=1;y<=n;y++)
					for (int z=1;z<=n;z++)
						p[y][z]=min(p[y][z],max(p[y][x],p[x][z]));
		cout<<"Scenario #"<<ii++<<endl;
		cout<<"Frog Distance = "<<p[1][2]<<endl;
		cout<<endl;
	}
   //system("pause");
   return 0;
}
