#include <cstdio>
#include <cmath>
#define MAX 10000000
#define sqrtMAX 3162
bool p[MAX+1]={};
void sieve(){
	p[2]=true;
	for (int i=3;i<=MAX;i+=2)
		p[i]=true;
	for (int i=3;i<=MAX;i+=2)
		if (p[i])
			if ((long long)i*i<=MAX)
				for (int j=i*i;j<=MAX;j+=2*i)
					p[j]=false;
}
int main()
{
	sieve();
	int n;
	long long v;
	scanf("%d",&n);
	while (n--){
		scanf("%lld",&v);
		long long st=(long long)sqrt(v);
		if (st*st==v&&p[st])
			puts("YES");
		else
			puts("NO");
	}
}
