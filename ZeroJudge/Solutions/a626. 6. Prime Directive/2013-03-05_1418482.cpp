#include <cstdio>

int prime[1000],pnum=0;
bool p[1001];
void init(){
	prime[pnum++]=2;
	for (int i=3;i<1000;i+=2)
		p[i]=true;
	for (int i=3;i<1000;i+=2)
		if (p[i]){
			prime[pnum++]=i;
			for (int j=i*i;j<1000;j+=2*i)
				p[j]=false;
		}
}
int main()
{
	init();
	int n;
	while (scanf("%d",&n)==1){
		int cnt=0;
		for (int i=0;i<pnum&&prime[i]<=n;i++){
			if (cnt==5)
				puts(""),cnt=0;
			printf("%10d",prime[i]);
			cnt++;
		}
		puts("");
	}
}
