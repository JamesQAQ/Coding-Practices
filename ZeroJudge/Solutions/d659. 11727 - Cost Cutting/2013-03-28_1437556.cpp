#include <stdio.h>
#include <algorithm>

int input()
{
	char c=getchar();
	while ((c!='-')&&(c>'9'||c<'0'))
		c=getchar();
	bool negative=(c=='-');
	int x=(negative)?0:c-48;
	c=getchar();
	while (c<='9'&&c>='0'){
		x=x*10+c-48;
		c=getchar();
	}
	return (negative)?-x:x;
}
int work(int a,int b,int c){
	int d[3];
	d[0]=a,d[1]=b,d[2]=c;
	std::stable_sort(d,d+3);
	return d[1];
}
int main()
{
	int cases;
	cases=input();
	for (int t=1;t<=cases;t++){
		printf("Case %d: ",t);
		printf("%d\n",work(input(),input(),input()));
	}
}
