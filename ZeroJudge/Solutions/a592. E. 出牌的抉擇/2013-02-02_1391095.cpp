#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

struct CARD{
	char s[11];
} card[13],tmp;
std::vector <CARD> ans[7];
int v[256],now[5];
void init(){
	for (int i=3;i<=9;i++)
		v[i+'0']=i-3;
	v['T']=7,v['J']=8,v['Q']=9,v['K']=10,v['A']=11,v['2']=12;
	v['S']=3,v['H']=2,v['D']=1,v['C']=0;
}
void pushans(int no,int num){
	tmp.s[0]='\0';
	for (int i=0;i<num;i++)
		strcat(tmp.s,card[now[i]].s);
	//printf("%s?\n",tmp.s);
	ans[no].push_back(tmp);
}
bool su(){
	for (int i=1;i<5;i++)
		if (v[card[now[i]].s[1]]-1!=v[card[now[i-1]].s[1]])
			return false;
	return true;
}
bool same(){
	for (int i=1;i<5;i++)
		if (card[now[0]].s[0]!=card[now[i]].s[0])
			return false;
	return true;
}
bool havetwo(){
	for (int i=0;i<5;i++)
		if (card[now[i]].s[1]=='2')
			return true;
	return false;
}
bool tigi(){
	char a=card[now[0]].s[1],b=card[now[1]].s[1];
	int cnta=0,cntb=0;
	for (int i=0;i<5;i++){
		if (card[now[i]].s[1]==a)
			cnta++;
		else if (card[now[i]].s[1]==b)
			cntb++;
	}
	return cnta==4||cntb==4;
}
bool fullhouse(){
	int num=1;
	char a[5]={card[now[0]].s[1]};
	int cnta[5]={1};
	for (int i=1;i<5;i++){
		int j=0;
		for (;j<num;j++)
			if (a[j]==card[now[i]].s[1]){
				cnta[j]++;
				break;
			}
		if (j==num){
			a[num]=card[now[i]].s[1];
			cnta[num]=1;
			num++;
		}
		if (num>2)
			return false;
	}
	return true;
}
void dfs(int x,int d){
	if (x==1)
		pushans(0,1);
	if (x==2&&card[now[0]].s[1]==card[now[1]].s[1])
		pushans(1,2);
	if (x==3&&card[now[0]].s[1]==card[now[1]].s[1]&&card[now[2]].s[1]==card[now[1]].s[1])
		pushans(2,3);
	if (x==5){
		bool a=su(),b=same(),c=havetwo();
		//printf("%d %d %d\n",a,b,c);
		if (a&&b&&!c)
			pushans(6,5);
		else if (tigi())
			pushans(5,5);
		else if (a&&!c)
			pushans(3,5);
		else if (fullhouse())
			pushans(4,5);
		return;
	}
	for (int i=d;i<13;i++){
		now[x]=i;
		dfs(x+1,i+1);
	}
}
bool cmp(CARD i,CARD j){
	if (i.s[1]!=j.s[1])
		return v[i.s[1]]<v[j.s[1]];
	return v[i.s[0]]<v[j.s[0]];
}
bool compar(char a,char b,char c,char d){
	if (b!=d)
		return v[b]<v[d];
	return v[a]<v[c];
}
bool sp(CARD i,CARD j){
	for (int k=9;k>=1;k-=2){
		if (compar(i.s[k-1],i.s[k],j.s[k-1],j.s[k])) return true;
		if (compar(j.s[k-1],j.s[k],i.s[k-1],i.s[k])) return false;
	}
}
bool sp2(CARD i,CARD j){
	for (int k=3;k>=1;k-=2){
		if (compar(i.s[k-1],i.s[k],j.s[k-1],j.s[k])) return true;
		if (compar(j.s[k-1],j.s[k],i.s[k-1],i.s[k])) return false;
	}
}
char full(CARD i){
	char a=i.s[1],b=i.s[9];
	int cnta=0,cntb=0;
	for (int k=1;k<=9;k+=2){
		if (i.s[k]==a)
			cnta++;
		else
			cntb++;
	}
	return (cnta==3)?a:b;
}
int sp4(CARD i,int a,CARD j,int b,int num){
	for (int k=0;k<num;k++){
		if (compar(i.s[a-1],i.s[a],j.s[b-1],j.s[b])) return 1;
		if (compar(j.s[b-1],j.s[b],i.s[a-1],i.s[a])) return 0;
		a-=2,b-=2;
	}
	return 2;
}
bool sp3(CARD i,CARD j){
	char a=full(i),b=full(j);
	if (a==i.s[1]){
		if (b==j.s[1]){
			if (sp4(i,5,j,5,3)!=2)
				return sp4(i,5,j,5,3);
			return sp4(i,9,j,9,2);
		}		
		else{
			if (sp4(i,5,j,9,3)!=2)
				return sp4(i,5,j,9,3);
			return sp4(i,9,j,3,2);
		}
	}
	else{
		if (b==j.s[1]){
			if (sp4(i,9,j,5,3)!=2)
				return sp4(i,9,j,5,3);
			return sp4(i,3,j,9,2);
		}		
		else{
			if (sp4(i,9,j,9,3)!=2)
				return sp4(i,9,j,9,3);
			return sp4(i,3,j,3,2);
		}
	}
}
int main()
{
	init();
	int cases;
	scanf("%d",&cases);
	for (int t=1;t<=cases;t++){
		printf("Case #%d:\n",t);
		for (int i=0;i<13;i++)
			scanf("%s",card[i].s);
		std::stable_sort(card,card+13,cmp);
		for (int i=0;i<7;i++)
			ans[i].clear();
		dfs(0,0);
		for (int i=0;i<7;i++){
			if (i==1)
				std::stable_sort(ans[i].begin(),ans[i].end(),sp2);
			if (i==3)
				std::stable_sort(ans[i].begin(),ans[i].end(),sp);
			if (i==4)
				std::stable_sort(ans[i].begin(),ans[i].end(),sp3);
			if (ans[i].size()==0)
				puts("No exists");
			else{
				for (int j=0;j<ans[i].size();j++)
					printf((j)?" %s":"%s",ans[i][j].s);
				puts("");
			}
		}
	}
}
/*
2
SA S2 C7 H3 H4 S4 C5 C6 C8 C9 CJ CK HK
SA S2 S3 H3 H4 S4 C4 S6 C6 C9 CQ CJ CK

Spade > Heart > Diamond > Club

2 > A > K > Q > J > T > 9 > 8 > 7 > 6 > 5 > 4 > 3
*/
