#include <cstdio>
#include <algorithm>

struct Node{
	int c,e;
} OAO[100000];
bool cmp(Node i,Node j){
	return i.e>j.e;
}
int main()
{
	int n;
	while (scanf("%d",&n),n){
		for (int i=0;i<n;i++)
			scanf("%d %d",&OAO[i].c,&OAO[i].e);
		std::stable_sort(OAO,OAO+n,cmp);
		int ans=0,sum=0;
		for (int i=0;i<n;i++){
			sum+=OAO[i].c;
			if (sum+OAO[i].e>ans)
				ans=sum+OAO[i].e;
		}
		printf("%d\n",ans);
	}
}
