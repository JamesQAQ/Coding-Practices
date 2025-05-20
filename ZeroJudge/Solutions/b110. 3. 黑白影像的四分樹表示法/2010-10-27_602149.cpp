#include<iostream>
using namespace std;

int n;
bool map[128][128];
void test(int x,bool m[128][128])
{
	bool t=m[0][0];
	int i,j;
	for (i=0;i<x;i++)
	{
		for (j=0;j<x;j++)
		{
			if (m[i][j]!=t)
			{
				cout<<"g ";
				bool mm[128][128];
				for (int i=0;i<x/2;i++)
					for (int j=x/2;j<x;j++)
						mm[i][j-x/2]=m[i][j];
				test(x/2,mm);
				for (int i=0;i<x/2;i++)
					for (int j=0;j<x/2;j++)
						mm[i][j]=m[i][j];
				test(x/2,mm);
				for (int i=x/2;i<x;i++)
					for (int j=0;j<x/2;j++)
						mm[i-x/2][j]=m[i][j];
				test(x/2,mm);
				for (int i=x/2;i<x;i++)
					for (int j=x/2;j<x;j++)
						mm[i-x/2][j-x/2]=m[i][j];
				test(x/2,mm);
				return;
			}
		}
	}
	if (i==x&&j==x)
	{
		char c=(t)?'b':'w';
		cout<<c<<" ";
	}
}
int main()
{
	char c;
	while (cin>>n)
	{
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				cin>>c;
				map[i][j]=((c-48))?1:0;
			}
		test(n,map);
		cout<<endl;
	}
	return 0;
}
