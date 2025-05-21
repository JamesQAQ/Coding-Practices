#include <cstdio>
#include <cmath>

int p,q,r,s,t,u;
double f(double x){
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u; 
}
double eps=1e-8;
void work(double l,double r){
	if ((f(l)>0&&f(r)<0)||(f(l)<0&&f(r)>0)){
		if (f(l)>0&&f(r)<0){
			while (r-l>eps){
				double mid=(l+r)/2;
				if (f(mid)>0)
					l=mid;
				else
					r=mid;
			}
			printf("%.4lf\n",fabs(l));
		}
		else{
			while (r-l>eps){
				double mid=(l+r)/2;
				if (f(mid)<0)
					l=mid;
				else
					r=mid;
			}
			printf("%.4lf\n",fabs(l));
		}
	}
	else
		puts("No solution");
}
int main()
{
	while (scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)==6)
		work(0-eps,1+eps);
}
