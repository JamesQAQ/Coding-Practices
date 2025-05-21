#include <cstdio>
#define base 1000000000

struct BigNumber{
	int a[10],num;
	void fixed(){
		for (int i=0;i<num-1;i++)
			if (a[i]>=base){
				a[i]-=base;
				a[i+1]++;
			}
		if (a[num-1]>=base){
			a[num-1]-=base;
			a[num]=1;
			num++;
		}
	}
	void operator +=(BigNumber b){
		if (num<b.num){
			for (int i=num;i<b.num;i++)
				a[i]=0;
			num=b.num;
		}
		for (int i=0;i<b.num;i++)
			a[i]+=b.a[i];
		fixed();
	}
	BigNumber operator +(BigNumber b){
		BigNumber c=b;
		if (c.num<num){
			for (int i=c.num;i<num;i++)
				c.a[i]=0;
			c.num=num;
		}
		for (int i=0;i<num;i++)
			c.a[i]+=a[i];
		c.fixed();
		return c;
	}
	void operator +=(int x){
		if (num==0)
			a[num++]=x;
		else
			a[0]+=x;
		fixed();
	}
	void init(){
		num=0;
	}
	void print(){
		if (num==0)
			printf("0");
		else{
			printf("%d",a[num-1]);
			for (int i=num-2;i>=0;i--)
				printf("%09d",a[i]);
		}
		puts("");
	}
	bool operator >(BigNumber b){
		if (num!=b.num)
			return num>b.num;
		for (int i=num-1;i>=0;i--){
			if (a[i]>b.a[i])
				return true;
			if (a[i]<b.a[i])
				return false;
		}
		
	}
} f[10001],g[10001];
int Q[10001],l,r;
int main()
{
	f[0].init();
	g[0].init();
	Q[r++]=0;
	int at=1;
	for (int i=1;i<=200;i++){
		f[i]=f[i-1]+f[i-1];
		f[i]+=1;
	}
	for (int i=1;i<=10000;i++){
		//printf("i %d\n",i);
		//f[i].print();
		//getchar();
		while (l+1<r&&((g[Q[l]]+g[Q[l]])+f[i-Q[l]])>((g[Q[l+1]]+g[Q[l+1]])+f[i-Q[l+1]]))
			l++;
		//printf("Q[l] %d %d\n",Q[l],i-Q[l]);
		//g[Q[l]].print(),f[i-Q[l]].print();
		//printf("%d %d %d\n",i,Q[l],f[i-Q[l]].num);
		g[i]=((g[Q[l]]+g[Q[l]])+f[i-Q[l]]);
		//printf("i %d\n",i);
		//g[i].print();
		//getchar();
		Q[r++]=i;
	}
	int n;
	while (scanf("%d",&n)==1)
		g[n].print();
}
