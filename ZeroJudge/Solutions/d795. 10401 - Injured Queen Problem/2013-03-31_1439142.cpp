#include <cstdio>
#include <cstring>

int abs(int x){
	return (x<0)?-x:x;
}
int A_A[256];
void init(){
	for (int i=0;i<10;i++)
		A_A[i+'0']=i;
	for (int i=0;i<26;i++)
		A_A[i+'A']=i+10;
}
int main()
{
	char s[20];
	long long dp[20][20];
	init();
	while (scanf("%s",s)==1){
		int n=strlen(s);
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				dp[i][j]=0;
		for (int i=0;i<n;i++)
			dp[0][i]=1;
		for (int i=0;i<n-1;i++){
			for (int j=0;j<n;j++)
				if (s[i]=='?'||A_A[s[i]]==j+1){
					for (int k=0;k<n;k++)
						if (abs(j-k)>1)
							dp[i+1][k]+=dp[i][j];
				}
		}
		long long ans=0;
		for (int i=0;i<n;i++)
			if (s[n-1]=='?'||A_A[s[n-1]]==i+1)
				ans+=dp[n-1][i];
		printf("%lld\n",ans);
	}
}
/*
??????
??????????????? 
???8?????
43?????
*/
