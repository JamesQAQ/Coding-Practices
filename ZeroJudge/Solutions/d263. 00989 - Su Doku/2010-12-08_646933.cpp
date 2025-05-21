#include <iostream>
using namespace std;

int n;
short map[9][9];
bool r[9][10],c[9][10],box[9][10],finish;
bool notok()
{
	for (int i=0;i<n*n;i++)
		for (int j=0;j<n*n;j++)
		{
			if (map[i][j]==0)
				continue;
			if (r[i][map[i][j]])
				return 1;
			r[i][map[i][j]]=1;
			if (c[j][map[i][j]])
				return 1;
			c[j][map[i][j]]=1;
			int x=i/n,y=j/n;
			if (box[x+n*y][map[i][j]])
				return 1;
			box[x+n*y][map[i][j]]=1;
		}
	return 0;
}
void dfs(int x,int y)
{
	if (y==n*n)
	{
		y=0;
		x++;
	}
	if (x==n*n)
	{
		finish=1;
		return;
	}
	int xx=x/n,yy=y/n;
	if (finish)
		return;
	if (map[x][y]!=0)
		dfs(x,y+1);
	else
	{
		for (int i=1;i<=n*n;i++)
		{
			if (r[x][i]||c[y][i]||box[xx+n*yy][i])
				continue;
			map[x][y]=i;
			r[x][i]=1;
			c[y][i]=1;
			box[xx+n*yy][i]=1;
			dfs(x,y+1);
			if (finish)
				return;
			r[x][i]=0;
			c[y][i]=0;
			box[xx+n*yy][i]=0;
			map[x][y]=0;
		}
	}
}
int main()
{
	while (cin>>n)
	{
		finish=0;
		for (int i=0;i<9;i++)
			for (int j=1;j<=n*n;j++)
			{
				r[i][j]=0;
				c[i][j]=0;
				box[i][j]=0;
			}
		for (int i=0;i<n*n;i++)
			for (int j=0;j<n*n;j++)
				cin>>map[i][j];
		if (notok())
		{
			cout<<"NO SOLUTION"<<endl;
			continue;
		}
		dfs(0,0);
		if (finish)
		{
			for (int i=0;i<n*n;i++)
			{
				for (int j=0;j<n*n;j++)
					cout<<map[i][j]<<" ";
				cout<<endl;
			}
		}
		else
			cout<<"NO SOLUTION"<<endl;
	}
	return 0;
}
