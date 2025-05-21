#include <stdio.h>

long long gcd(long long m,long long n){
	while ((m%=n)&&(n%=m));
	return m+n;
}
long long abs(long long x){
	return (x<0)?-x:x;
}
long long lcm(long long x,long long y){
	long long g=gcd(x,y);
	long long v=x/g;
	if (v>1000000000000000000LL/y)
		return -1;
	else
		return v*y;
}
int main()
{
	long long a,b,x,y;
	scanf("%lld %lld %lld %lld",&a,&b,&x,&y);
	x=abs(x);
	y=abs(y);
	if (x==0||y==0){
		if (a<=0&&b>=0)
			puts("1");
		else
			puts("0");
	}
	else{
		if (a<0&&b<0){
			a=abs(a);
			b=abs(b);
			b--;
			long long g=lcm(x,y);
			if (g!=-1)
				printf("%lld\n",a/x-b/x+a/y-b/y-(a/g-b/g));
			else
				printf("%lld\n",a/x-b/x+a/y-b/y);				
		}
		else if (a>0&&b>0){
			a--;
			long long g=lcm(x,y);
			if (g!=-1)
				printf("%lld\n",b/x-a/x+b/y-a/y-(b/g-a/g));
			else
				printf("%lld\n",b/x-a/x+b/y-a/y);				
		}
		else if (a<0&&b==0){
			a=abs(a);
			long long g=lcm(x,y);
			if (g!=-1)
				printf("%lld\n",a/x+a/y-a/g+1);	
			else
				printf("%lld\n",a/x+a/y+1);							
		}
		else if (a==0&&b>0){
			long long g=lcm(x,y);
			if (g!=-1)
				printf("%lld\n",b/x+b/y-b/g+1);	
			else
				printf("%lld\n",b/x+b/y+1);				
		}
		else if (a<0&&b>0){
			a=abs(a);
			long long g=lcm(x,y);
			if (g!=-1)
				printf("%lld\n",a/x+b/x+a/y+b/y-a/g-b/g+1);
			else
				printf("%lld\n",a/x+b/x+a/y+b/y+1);
		}
		else
			puts("0");
	}
}
