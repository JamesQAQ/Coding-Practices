#include <cstdio>
#include <cstring>

char key[24][3]={"C","C#","D","D#","E","F","F#","G","G#","A","A#","B","C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
char s[1000];
int judgekey(char s[]){
	for (int i=0;;i++)
		if (strcmp(s,key[i])==0)
			return i;
}
int move[7]={2,2,1,2,2,2,1};
char QAQ[7][3];
void build(int x){
	for (int i=0;i<7;i++){
		strcpy(QAQ[i],key[x]);
		x+=move[i];
		//puts(QAQ[i]);
	}
}
void work(char s[]){
	int pos=0;
	for (int i=0;s[i];i++){
		int j=i+1,x=0;
		while (s[j]<='9'&&s[j]>='0')
			x=x*10+s[j]-48,j++;
		x--;
		x%=7;
		if (s[i]=='+')
			pos=(pos+x)%7;
		else
			pos=((pos-x)%7+7)%7;
		printf(" %s",QAQ[pos]);
		i=j-1;
	}
}
int main()
{
	char tmps[3];
	while (scanf("%s",s)==1){
		int at=1;
		if (s[1]=='#')
			at=2;
		tmps[0]=s[0];
		tmps[at]=0;
		if (at==2)
			tmps[1]='#';
		int now=judgekey(tmps);
		printf("%s",tmps);
		build(now);
		work(s+at);
		puts("");
	}
}
