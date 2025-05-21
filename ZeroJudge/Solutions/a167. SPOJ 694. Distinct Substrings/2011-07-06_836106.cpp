#include <cstdio>
#include <cstring>
#include <algorithm>

struct Node {int at,v;} data[5000];
int rank[5000],len,pow2[14],dis[5001],top,temp,sa[5000],height[5000];
char s[5001];
bool cmp(Node i,Node j){
	return i.v<j.v;
}
void double_algorithm(){
	bool mark[5000]={};
	for (int i=0;i<len;i++)
		rank[i]=s[i],data[i].at=i,data[i].v=rank[i];
	std::sort(data,data+len,cmp);
	for (int i=0;pow2[i]<len;i++){
		dis[0]=-1,rank[data[0].at]=1,top=1,temp=data[0].v,data[0].v;
		for (int j=1;j<len;j++){
			if (mark[j]||data[j].v!=temp)
				dis[top++]=j-1,temp=data[j].v,mark[j]=true;
			rank[data[j].at]=top;
		}
		dis[top++]=len-1;
		for (int j=0;j<len;j++)
			data[j].v=(data[j].at+pow2[i]<len)?rank[data[j].at+pow2[i]]:0;
		for (int j=1;j<top;j++)
			std::sort(data+dis[j-1]+1,data+dis[j]+1,cmp);
	}
	for (int i=0;i<len;i++)
		sa[i]=data[i].at;
}
void count_height(){
	for (int i=0;i<len;i++)
		rank[sa[i]]=i;
	int k=0;
	for (int i=0;i<len;i++){
		if (rank[i]==0){
			height[rank[i]]=0;
			continue;
		}
		if (k)
			k--;
		while (s[sa[rank[i]-1]+k]==s[i+k])
			k++;
		height[rank[i]]=k;
	}
}
int main()
{
	pow2[0]=1;
	for (int i=1;i<14;i++)
		pow2[i]=pow2[i-1]*2;
	int cases;
	scanf("%d",&cases);
	while (cases--){
		scanf("%s",s);
		len=strlen(s);
		double_algorithm();
		count_height();
		int sum=0;
		for (int i=0;i<len;i++)
			sum+=len-sa[i]-height[i];
		printf("%d\n",sum);
	}
	return 0;
}
