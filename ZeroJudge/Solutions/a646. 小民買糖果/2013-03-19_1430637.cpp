#include <cstdio>

int get(char s[]){
	int at=-1;
	for (int i=0;s[i];i++)
		if (s[i]=='.')
			at=i+1;
	if (at==-1)
		return 0;
	int x=0,num=100;
	for (int i=at;s[i];i++)
		x+=num*(s[i]-48),num/=10;
	return x;
}
int dp[1001];
int max(int a,int b){
	return (a>b)?a:b;
}
int main()
{
	int c,p;
	char s[100];
	while (scanf("%d",&c)==1){
		scanf("%s",s);
		p=get(s);
		for (int i=0;i<c;i++)
			dp[i]=0;
		dp[c]=c;
		for (int i=c;i>0;i--){
			for (int j=1;j<=i;j++){
				int v=(j*p)/1000;
				dp[i-j+v]=max(dp[i-j+v],dp[i]+v);
			}
			//printf("i %d dp %d\n",i,dp[i]);
		}
		printf("%d\n",dp[0]);
	}
}
