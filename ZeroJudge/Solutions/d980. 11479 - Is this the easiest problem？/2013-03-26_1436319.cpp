#include <cstdio>

int main()
{
	int cases;
	long long a,b,c;
	scanf("%d",&cases);
	for (int t=1;t<=cases;t++){
		printf("Case %d: ",t);
		scanf("%lld %lld %lld",&a,&b,&c);
		if (a+b<=c||b+c<=a||c+a<=b)
			puts("Invalid");
		else if (a==b&&b==c)
			puts("Equilateral");
		else if (a==b||b==c||c==a)
			puts("Isosceles");
		else
			puts("Scalene");
	}
}
/*
4
1 2 5
1 1 1
4 4 2
3 4 5
*/
