#include <cstdio>
#include <cmath>

int check(long long a,long long b,long long n){
	b-=a-1;
	//printf("%lld %lld %lld\n",a,b,n);
	/*if (b==2)
		return 2;*/
	if (b==2)
		return 2;
	if (b>0&&b%2==0)
		return 1;
	return 0;
}
#define MAX 31000000
bool p[MAX+1]={};
int prime[2000000],pnum=0;
void init(){
	p[2]=true;
	prime[pnum++]=2;
	for (int i=3;i<MAX;i+=2)
		p[i]=true;
	for (int i=3;i<MAX;i+=2)
		if (p[i]){
			prime[pnum++]=i;
			if ((long long)i*i<=MAX)
				for (int j=i*i;j<=MAX;j+=2*i)
					p[j]=false;
		}
	//printf("%d\n",pnum);
}
int c[10000],cn[10000],dnum,d[100000];
void dfs(long long x,int at,long long limit,int num){
	if (x>limit)
		return;
	if (at==num){
		d[dnum++]=x;
		return;
	}
	long long tmp=1;
	for (int i=0;i<=cn[at];i++){
		dfs(x*tmp,at+1,limit,num);
		tmp*=c[at];
	}
}
int build(long long n){
	int num=0;
	long long limit=sqrt(n);
	for (int i=0;i<pnum&&prime[i]<=limit;i++)
		if (n%prime[i]==0){
			int cnt=0;
			while (n%prime[i]==0){
				n/=prime[i];
				cnt++;
			}
			c[num]=prime[i];
			cn[num]=cnt;
			num++;
		}
	/*printf("n %lld\n",n);
	for (int i=0;i<num;i++)
		printf("%d %d???\n",c[i],cn[i]);*/
	dnum=0;
	dfs(1,0,limit,num);
	return dnum;
}
int main()
{
	init();
	long long n;
	while (scanf("%lld",&n)==1){
		if (n==0){
			puts("1");
			continue;
		}
		n*=2;
		int ans=0;
		int num=build(n);
		for (int i=0;i<num;i++){
			//printf("d %d\n",d[i]);
			ans+=check(d[i],n/d[i],n);
			if (n!=n/d[i])
				ans+=check(n/d[i],d[i],n);
		}
		printf("%d\n",ans);
	}
}
