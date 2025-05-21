#include <cstdio>
#include <cstring>

char s[100000];
int max(int a,int b){
	return (a>b)?a:b;
}
int len;
int pa(int l,int r){
	while (l-1>=0&&r+1<len&&s[l-1]==s[r+1])
		l--,r++;
	return r-l+1;
}
int main()
{
	int cases,ans;
	scanf("%d",&cases);
	while (cases--){
		ans=1;
		scanf("%s",s);
		len=strlen(s);
		for (int i=0;i<len;i++){
			if (i)
				ans=max(ans,pa(i,i-1));
			ans=max(ans,pa(i,i));
		}
		printf("%d\n",ans);
	}
}
