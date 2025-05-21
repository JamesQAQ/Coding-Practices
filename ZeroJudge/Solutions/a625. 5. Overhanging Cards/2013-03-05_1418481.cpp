#include <cstdio>

int main()
{
	double x;
	while (scanf("%lf",&x)==1){
		int cnt=0;
		double sum=0;
		while (sum<x){
			sum+=(double)1/(cnt+2);
			cnt++;
		}
		printf("%d card(s)\n",cnt);
	}
}
