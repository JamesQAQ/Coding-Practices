#include <iostream>
#include <algorithm>
using namespace std;

long long int c[1000];
int n;
short d[1000];
bool cmp(int i,int j)
{
	if (c[i]>c[j])
		return 1;
	if (c[i]<c[j])
		return 0;
	if (d[i]>d[j])
		return 1;
	if (d[i]<d[j])
		return 0;
	return 1;
}
int main()
{
	int a,b,t[1000];
	while (cin>>n)
	{
		if (n==0)
			break;
		for (int i=0;i<n;i++)
		{
			cin>>a>>b;
			c[i]=a+b;
			if (a>b)
				d[i]=2;
			else if (a<b)
				d[i]=0;
			else
				d[i]=1;
			t[i]=i;
		}
		stable_sort(t,t+n,cmp);
		for (int i=0;i<n;i++)
		{
			if (d[t[i]]==2)
				cout<<">";
			else if (d[t[i]]==0)
				cout<<"<";
			else
				cout<<"=";
			cout<<c[t[i]]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
