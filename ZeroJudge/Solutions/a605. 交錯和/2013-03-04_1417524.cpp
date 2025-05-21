#include <cstdio>

long long deque[2][1000001];
int l[2],r[2],pos[2][1000001];
int input(){
	char c=getchar();
	while (c!='-'&&(c>'9'||c<'0')) c=getchar();
	bool negative=(c=='-');
	int x=(negative)?0:c-48;
	c=getchar();
	while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
	return (negative)?-x:x;
}
int main()
{
	int n,m,tmp;
	scanf("%d %d",&n,&m);
	l[0]=l[1]=r[0]=r[1]=0;
	long long ans,vv[2];
	bool vvv[2];
	bool one=false;
	for (int i=0;i<n;i++){
		tmp=input();
		for (int j=0;j<2;j++)
			if (l[j]<r[j]&&pos[j][l[j]]<i-m)
				l[j]++;
		for (int j=0;j<2;j++)
			vv[j]=deque[j][l[j]],vvv[j]=(l[j]<r[j]);
		for (int j=0;j<2;j++)
			if (vvv[j]||j==1){
				int k=(!j);
				long long v=vv[j]+((j)?tmp:-tmp);
				if (j==1&&(!vvv[j]||tmp>v))
					v=tmp;
				if (!one||v>ans)
					ans=v,one=true;
				while (l[k]<r[k]&&deque[k][r[k]-1]<v)
					r[k]--;
				deque[k][r[k]]=v;
				pos[k][r[k]]=i;
				r[k]++;
			}
	}
	printf("%lld\n",ans);
}
