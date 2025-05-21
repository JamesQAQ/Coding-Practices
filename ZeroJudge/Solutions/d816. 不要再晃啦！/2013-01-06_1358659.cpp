#include <cstdio>

int abs(int x){
	return (x<0)?-x:x;
}
int main()
{
	int n,m,a[1000];
	while (scanf("%d %d",&n,&m)==2){
		for (int i=0;i<m;i++)
			scanf("%d",&a[i]);
		for (int i=n;i<m;i++){
			int dis=abs(a[i]-a[i-n]);
			printf((i==n)?"%d":" %d",(dis==0)?0:(dis-1)/n+1);
		}
		puts("");
	}
}
