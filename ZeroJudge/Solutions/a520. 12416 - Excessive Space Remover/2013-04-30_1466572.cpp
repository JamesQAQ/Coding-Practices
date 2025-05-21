#include <cstdio>

char s[1000000];
int main()
{
	while (gets(s)!=NULL){
		int x=0,maxx=0;
		for (int i=0;s[i];i++){
			if (s[i]!=' ')
				x=0;
			else
				x++;
			if (x>maxx)
				maxx=x;
		}
		int ans=1;
		while ((1<<(ans-1))<maxx)
			ans++;		
		if (maxx==0)
			puts("0");
		else
			printf("%d\n",ans-1);
	}
}
