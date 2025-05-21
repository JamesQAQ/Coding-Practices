#include <cstdio>

int main()
{
	int cases,e,f,c;
	scanf("%d",&cases);
	while (cases--){
		scanf("%d %d %d",&e,&f,&c);
		int ans=0;
		f+=e;
		e=0;
		while (f>=c){
			e=f/c;
			f%=c;
			ans+=e;
			f+=e;
		}
		printf("%d\n",ans);
	}
}
