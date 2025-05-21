#include <cstdio>

char s[100];
struct Node{
	int next[128],cnt;
	void init(){
		for (int i=0;i<128;i++)
			next[i]=-1;
		cnt=0;
	}
} trie[300001];
int treenum,all;
void insert(char s[]){
	int at=0;
	for (int i=0;s[i];i++){
		int v=s[i];
		if (trie[at].next[v]==-1){
			trie[treenum].init();
			trie[at].next[v]=treenum;
			treenum++;
		}
		at=trie[at].next[v];
	}
	trie[at].cnt++;
}
char ans[100];
void dfs(int x,int d){
	if (trie[x].cnt){
		ans[d]=0;
		printf("%s %.4lf\n",ans,((double)trie[x].cnt*100)/all);
	}
	for (int i=0;i<128;i++)
		if (trie[x].next[i]!=-1){
			ans[d]=i;
			dfs(trie[x].next[i],d+1);
		}
}
int main()
{
	bool first=true;
	gets(s);
	while (gets(s)!=NULL){
		if (s[0]=='\0'){
			if (first)
				first=false;
			else
				dfs(0,0),puts("");
			treenum=1;
			trie[0].init();
			all=0;
		}
		else{
			insert(s);
			all++;
		}
	}
	dfs(0,0);
}
