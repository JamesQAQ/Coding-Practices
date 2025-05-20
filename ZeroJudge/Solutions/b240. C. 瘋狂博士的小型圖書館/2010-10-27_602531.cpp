#include <iostream>
#include <algorithm>
using namespace std;

char book[100][101],name[100][30],value[27]={"XOBCDAFGHUJKLMNIPQRSTEVWYZ"},v[256];
string ss[100];
int y[100];
bool cmp(int i,int j)
{
	for (int k=0;k<30;k++)
	{
		if (v[name[i][k]]>v[name[j][k]]) return 1;
		if (v[name[i][k]]<v[name[j][k]]) return 0;
	}
	if (y[i]>y[j]) return 0;
	if (y[i]<y[j]) return 1;
	for (int k=0;k<101;k++)
	{
		if (v[book[i][k]]>v[book[j][k]]) return 1;
		if (v[book[i][k]]<v[book[j][k]]) return 0;
	}
	return 1;
}
int main()
{
	v[' ']=27;
	v['.']=26;
	for (int i=0;i<26;i++)
	{
		v[value[i]]=25-i;
		v[value[i]+32]=25-i;
	}
	int n,t[100];
	string s;
	while (scanf("%d",&n)!=EOF)
	{
		getline(cin,s);
		for (int i=0;i<n;i++)
		{
			t[i]=i;
			for (int j=0;j<101;j++)
				book[i][j]=0;
			for (int j=0;j<30;j++)
				name[i][j]=0;
			getline(cin,s);
			int len=s.length(),d;
			ss[i]=s;
			for (d=0;d<len;d++)
			{
				if (s[d]==',')
					break;
				name[i][d]=s[d];
			}
			d+=2;
			int dd;
			for (dd=d;dd<len;dd++)
			{
				if (s[dd]=='(')
					break;
				book[i][dd-d]=s[dd];
			}
			dd++;
			int sum=0,ddd;
			for (ddd=dd;ddd<dd+4;ddd++)
				sum=sum*10+s[ddd]-48;
			y[i]=sum;
		}
		stable_sort(t,t+n,cmp);
		for (int i=0;i<n;i++)
			cout<<ss[t[i]]<<endl;
	}
	return 0;
}
