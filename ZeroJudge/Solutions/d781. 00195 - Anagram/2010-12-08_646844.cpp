#include <iostream>
using namespace std;

int n,num[150];
char ans[100000];
void dfs(int x)
{
	if (x==n)
	{
		for (int i=0;i<n;i++)
			cout<<ans[i];
		cout<<endl;
	}
	for (int i=0;i<26;i++)
	{
		if (num[i+'A']>0)
		{
			num[i+'A']--;
			ans[x]=i+'A';
			dfs(x+1);
			num[i+'A']++;
		}
		if (num[i+'a']>0)
		{
			num[i+'a']--;
			ans[x]=i+'a';
			dfs(x+1);
			num[i+'a']++;
		}
	}
}
int main()
{
	string s;
	int t;
	while (cin>>t)
		while (t-->0)
		{
			cin>>s;
			n=s.length();
			for (int i=0;i<26;i++)
			{
				num[i+'a']=0;
				num[i+'A']=0;
			}
			for (int i=0;i<n;i++)
				num[s[i]]++;
			dfs(0);
		}
	return 0;
}
