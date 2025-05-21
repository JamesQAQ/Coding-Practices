#include <cstdio>
#include <cstring>

char s[1000];
double eps=1e-6;
int main()
{
	int n;
	char s[1000];
	while (scanf("%d %s",&n,s)==2){
		double max=0.0;
		int len=strlen(s);
		for (int i=0;i<len;i++){
			int sum=0;
			for (int j=i;j<len;j++){
				if (s[j]=='C'||s[j]=='c'||s[j]=='g'||s[j]=='G')
					sum++;
				if (j-i+1>=n)
					if ((double)sum/(j-i+1)>max)
						max=(double)sum/(j-i+1);
			}
		}
		printf("%.2lf\n",max+eps);
	}
}
