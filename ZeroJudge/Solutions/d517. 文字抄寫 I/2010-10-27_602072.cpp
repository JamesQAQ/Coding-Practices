#include<iostream>
#include<algorithm>
using namespace std;

bool use[26][26][26][26];
int at[26][26][26][26];
int main()
{
	int n,sum;
	char s[5];
	while (scanf("%d",&n)!=EOF)
	{
		memset(use,0,sizeof(use));
		sum=1;
		for (int i=0;i<n;i++)
		{
			scanf("%s",s);
			for (int j=0;j<4;j++)
				s[j]=s[j]-'a';
			if (!use[s[0]][s[1]][s[2]][s[3]])
			{
				use[s[0]][s[1]][s[2]][s[3]]=1;
				at[s[0]][s[1]][s[2]][s[3]]=sum;
				printf("New! %d\n",sum++);
			}
			else
				printf("Old! %d\n",at[s[0]][s[1]][s[2]][s[3]]);
		}
	}
	return 0;
}
