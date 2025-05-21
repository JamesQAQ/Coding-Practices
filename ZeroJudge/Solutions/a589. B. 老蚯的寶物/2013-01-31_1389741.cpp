#include <cstdio>

char s[2010][2010];
int at[2010];
int main()
{
	int cases,n,temp;
	scanf("%d",&cases);
	char tmp[1000];
	while (cases--){
		at[0]=0;
		s[0][0]='\0';
		int num=1;
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%s",tmp);
			if (tmp[0]=='u'){
				scanf("%d",&temp);
				at[i]=at[i-1-temp];
			}
			else if (tmp[4]=='f'){
				scanf(" %c",&s[num][0]);
				int len=1;
				for (int j=0;s[at[i-1]][j];j++)
					s[num][len++]=s[at[i-1]][j];
				s[num][len]='\0';
				at[i]=num++;
			}
			else{
				int len=0;
				for (int j=0;s[at[i-1]][j];j++)
					s[num][len++]=s[at[i-1]][j];
				scanf(" %c",&s[num][len]);
				len++;
				s[num][len]='\0';
				at[i]=num++;
			}
			puts(s[at[i]]);
		}
	}
}

/*
2
9
pushfront m
pushfront t
pushback t
undo 2
undo 1
pushback 5
pushback 1
pushback 4
undo 5
3
pushfront 1
pushfront 5
pushback 4
*/
