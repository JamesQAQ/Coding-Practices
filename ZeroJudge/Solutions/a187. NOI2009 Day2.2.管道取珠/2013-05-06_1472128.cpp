/**********************************************************************************/
/*  Problem: a187 "NOI2009 Day2.2.管道取珠" from NOI2009 Day2 第二?       */
/*  Language: CPP (1136 Bytes)                                                    */
/*  Result: NA(score:90) judge by this@ZeroJudge                                  */
/*  Author: no306100 at 2013-05-06 16:53:25                                       */
/**********************************************************************************/


#include <cstdio>

int mod=1024523,dp[2][1001][1001];
char sa[1001],sb[1001];
void swap(char &a,char &b){
	char tmp=a;a=b,b=tmp;
}
void inverse(int len,char s[]){
	for (int i=0;i<len/2;i++)
		swap(s[i],s[len-i-1]);
}
void plus(int &a,int b){
	a+=b;
	if (a>=mod)
		a-=mod;
}
int main()
{
	int lena,lenb,len;
	scanf("%d %d %s %s",&lena,&lenb,sa,sb);
	inverse(lena,sa);
	inverse(lenb,sb);
	len=lena+lenb;
	for (int i=0;i<=lena;i++)
		for (int j=0;j<=lena;j++)
			dp[0][i][j]=0;
	dp[0][0][0]=1;
	for (int k=0;k<len;k++){
		int now=k%2;
		int next=(k+1)%2;
		for (int i=0;i<=lena;i++)
			for (int j=0;j<=lena;j++)
				dp[next][i][j]=0;
		for (int i=0;i<=k&&i<=lena;i++)
			for (int j=0;j<=k&&j<=lena;j++)
				if (dp[now][i][j]){
					if (i<lena&&j<lena&&sa[i]==sa[j])
						plus(dp[next][i+1][j+1],dp[now][i][j]);
					if (k-i<lenb&&j<lena&&sb[k-i]==sa[j])
						plus(dp[next][i][j+1],dp[now][i][j]);
					if (i<lena&&k-j<lenb&&sa[i]==sb[k-j])
						plus(dp[next][i+1][j],dp[now][i][j]);
					if (k-i<lenb&&k-j<lenb&&sb[k-i]==sb[k-j])
						plus(dp[next][i][j],dp[now][i][j]);
				}
	}
	printf("%d\n",dp[len%2][lena][lena]);
}
