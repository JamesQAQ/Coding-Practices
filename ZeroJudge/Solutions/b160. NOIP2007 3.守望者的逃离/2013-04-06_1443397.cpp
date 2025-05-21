#include <cstdio>

int min(int a,int b){
	return (a<b)?a:b;
}
int main()
{
	int M,S,T,ans=0,tim=2147483647;
	scanf("%d %d %d",&M,&S,&T);
	for (int i=0;i<T;i++){
		int MM=M+i*4,mini=min(T-i,MM/10);
		int p=mini*60+(T-i-mini)*17;
		if (p>ans)
			ans=p;
		if (p>S){
			if (mini*60>=S)
				tim=min(tim,(S-1)/60+1+i);
			else
				tim=min(tim,i+mini+(S-mini*60-1)/17+1);
		}
	}
	printf("%s\n%d\n",(ans>=S)?"Yes":"No",(ans>=S)?tim:ans);
}
