#include <cstdio>

int min(int a,int b){
	return (a<b)?a:b;
}
int main()
{
	int a,b;
	while (scanf("%d %d",&a,&b)==2){
		if (a==-1&&b==-1)
			break;
		if (a>b)
			a^=b^=a^=b;
		printf("%d\n",min(100+a-b,b-a));
	}
}
