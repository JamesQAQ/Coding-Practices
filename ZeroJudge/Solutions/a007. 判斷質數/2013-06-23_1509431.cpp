#include <cstdio>
#define MAX 46340

bool p[MAX+1]={};
int prime[MAX],pnum;
void sieve(){
	pnum=0;
	prime[pnum++]=2;
	p[2]=true;
	for (int i=3;i<MAX;i+=2)
		p[i]=true;
	for (int i=3;i<MAX;i+=2)
		if (p[i]){
			prime[pnum++]=i;
			for (int j=i*i;j<MAX;j+=2*i)
				p[j]=false;
		}
}
inline bool work(int n){
	if (n<MAX)
		return p[n];
	for (int i=0;i<pnum&&prime[i]*prime[i]<=n;i++)
		if (n%prime[i]==0)
			return false;
	return true;
}
int main()
{
	int n;
	sieve();
	while (scanf("%d",&n)==1)
		puts((work(n))?"質數":"非質數");
}
