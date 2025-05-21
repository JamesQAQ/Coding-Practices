#include <cstdio>
#include <cstring>

char good[1000][81],name[81],ansname[81];
bool match(char tmp[],int n){
	for (int i=0;i<n;i++)
		if (strcmp(good[i],tmp)==0)
			return true;
	return false;
}
int main()
{
	char tmp[81];
	bool first=true;
	int n,m,cases=0;
	while (scanf("%d %d",&n,&m)){
		if (n==0&&m==0)
			break;
		gets(good[0]);
		for (int i=0;i<n;i++)
			gets(good[i]);//,puts(good[i]);
		double mini,v;
		int maxx=-1,p;
		for (int i=0;i<m;i++){
			gets(name);
			scanf("%lf %d",&v,&p);
			gets(tmp);
			int cnt=0;
			for (int i=0;i<p;i++){
				gets(tmp);
				if (match(tmp,n))
					cnt++;
			}
			if (cnt>maxx){
				maxx=cnt;
				mini=v;
				strcpy(ansname,name);
			}
			else if (cnt==maxx&&v<mini){
				mini=v;
				strcpy(ansname,name);
			}
		}
		if (first) first=false;
		else puts("");
		printf("RFP #%d\n",++cases);
		puts(ansname);
	}
}
/*
6 4
engine
brakes
tires
ashtray
vinyl roof
trip computer
Chevrolet
20000.00 3
engine
tires
brakes
Cadillac
70000.00 4
ashtray
vinyl roof
trip computer
engine
Hyundai
10000.00 3
engine
tires
ashtray
Lada
6000.00 1
tires
1 1
coffee
Starbucks
1.50 1
coffee
0 0
*/
