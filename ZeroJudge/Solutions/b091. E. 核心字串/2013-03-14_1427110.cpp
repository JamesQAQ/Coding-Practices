#include <cstdio>
#include <cstring>

char s[2000000];
int cnt[26];
int main()
{
	int n;
	while (scanf("%d",&n),n){
		gets(s);
		gets(s);
		for (int i=0;i<26;i++)
			cnt[i]=0;
		int all=0,len=strlen(s),at=0;
		int ansl=-1,ansr;
		for (int i=0;i<len;i++){
			//printf("i %d\n",i);
			while (all<26&&at<len){
				cnt[s[at]-48]++;
				if (cnt[s[at]-48]==1)
					all++;
				//printf("%d %d\n",at,all);
				at++;
			}
			if (all==26){
				if (ansl==-1||at-i<ansr-ansl)
					ansl=i,ansr=at;
			}
			cnt[s[i]-48]--;
			if (cnt[s[i]-48]==0)
				all--;
		}
		if (ansl==-1)
			puts("not found");
		else{
			for (int i=ansl;i<ansr;i++)
				putchar(s[i]);
			puts("");
		}
	}
}
