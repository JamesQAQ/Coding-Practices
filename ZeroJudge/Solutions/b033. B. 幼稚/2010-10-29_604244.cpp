#include <iostream>
using namespace std;

int main()
{
	int m,n,p,r,v[5]={1,10,100,1000,10000};
	while (cin>>m>>n>>p>>r)
	{
		if (m==0&&n==0&&p==0&&r==0)
			break;
		int k=m%v[p],g=n%v[p];
		if (m==1&&n==1)
		{
			cout<<"Draw with 1."<<endl;
			continue;
		}
		if ((m==1||n==1)||m==n)
		{
			k=(m==1)?n:m;
			for (int i=1;i<r;i++)
				k=k*k%v[p];
			cout<<"Draw with "<<k<<"."<<endl;
			continue;
		}
		if (m==n)
		{
			k=(m==1)?n:m;
			for (int i=0;i<r;i++)
				k=k*k%v[p];
			cout<<"Draw with "<<k<<"."<<endl;
			continue;
		}
		for (int i=0;i<r;i++)
		{
			if (m>n)
			{
				if (i%2==0)
					g=g*k%v[p];
				else
					k=k*g%v[p];
			}
			else
			{
				if (i%2==1)
					g=g*k%v[p];
				else
					k=k*g%v[p];
			}
		}
		if (m>n)
		{
			if (r%2==1)
				cout<<"The ghost of childish won the game with "<<g<<"."<<endl;
			else
				cout<<"The king of childish won the game with "<<k<<"."<<endl;
		}
		else
		{
			if (r%2==0)
				cout<<"The ghost of childish won the game with "<<g<<"."<<endl;
			else
				cout<<"The king of childish won the game with "<<k<<"."<<endl;
		}
	}
}
