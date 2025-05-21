#include <cstdio>
#include <cmath>
#include <algorithm>

struct Node{
	long long x,y;
} node[3000000],tmp[3000000];
bool cmp(Node i,Node j){
	if (i.x!=j.x)
		return i.x<j.x;
	return i.y<j.y;
}
unsigned long long MAX=1000000000000000000ULL;
unsigned long long min(unsigned long long a,unsigned long long b){
	return (a<b)?a:b;
}
unsigned long long Abs(long long x){
	if (x<0)
		x=-x;
	return (unsigned long long)x;
}
unsigned long long merge(int l,int r){
	if (l==r)
		return MAX;
	int mid=(l+r)/2;
	unsigned long long mind=MAX;
	Node middle=node[mid]; 
	mind=min(mind,merge(l,mid));
	mind=min(mind,merge(mid+1,r));
	for (int i=l;i<=r;i++)
		tmp[i]=node[i];
	int atl=l,atr=mid+1;
	for (int i=l;i<=r;i++){
		if (atr==r+1||(atl<=mid&&tmp[atl].y<tmp[atr].y))
			node[i]=tmp[atl++];
		else
			node[i]=tmp[atr++];
	}
	int num=0;
	for (int i=l;i<=r;i++)
		if (Abs(middle.x-node[i].x)*Abs(middle.x-node[i].x)<MAX)
			tmp[num++]=node[i];
	for (int i=l;i<=r;i++)
		for (int j=1;j<=5&&i+j<=r;j++)
			mind=min(mind,Abs(tmp[i+j].x-tmp[i].x)*Abs(tmp[i+j].x-tmp[i].x)+Abs(tmp[i+j].y-tmp[i].y)*Abs(tmp[i+j].y-tmp[i].y));
	return mind;
}
int input(){
	char c=getchar();
	while ((c!='-')&&(c>'9'||c<'0')) c=getchar();
	bool negative=(c=='-');
	int x=(negative)?0:c-48;
	c=getchar();
	while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
	return (negative)?-x:x;
}
int main()
{
	int n;
	while (scanf("%d",&n)==1){
		for (int i=0;i<n;i++)
			node[i].x=input(),node[i].y=input();
		std::stable_sort(node,node+n,cmp);
		printf("%.4lf\n",sqrt(merge(0,n-1)));
	}
}
