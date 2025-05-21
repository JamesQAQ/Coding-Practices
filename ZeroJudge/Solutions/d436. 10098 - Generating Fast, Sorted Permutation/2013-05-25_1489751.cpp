#include <cstdio>
#include <cstring>

char s[100];
int cnt[52];
void init(char s[]){
	for (int i=0;i<52;i++)
		cnt[i]=0;
	for (int i=0;s[i];i++){
		if ('a'<=s[i]&&s[i]<='z')
			cnt[s[i]-'a'+26]++;
		else
			cnt[s[i]-'A']++;
	}
}
int len;
char now[100];
void dfs(int x){
	//printf("dfs %d\n",x);
	if (x==len){
		puts(now);
		return;
	}
	for (int i=0;i<52;i++)
		if (cnt[i]){
			cnt[i]--;
			now[x]=i+((i<26)?'A':('a'-26));
			dfs(x+1);
			cnt[i]++;
		}
}
int main()
{
	bool first=true;
	int cases;
	scanf("%d",&cases);
	while (cases--){
		scanf("%s",s);
		len=strlen(s);
		init(s);
		now[len]='\0';
		if (first) first=false;
		else puts("");
		dfs(0);
	}
}
