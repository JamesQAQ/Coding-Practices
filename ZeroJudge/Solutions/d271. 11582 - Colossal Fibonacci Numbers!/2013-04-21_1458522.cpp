#include <cstdio>

bool mark[1000][1000]={};
int cycle[1001][3000],num[1001];
void init(){
	for (int i=1;i<=1000;i++){
		//printf("i %d\n",i);
		num[i]=2;
		cycle[i][0]=0,cycle[i][1]=1%i;
		mark[0][1%i]=true;
		while (1){
			int v=(cycle[i][num[i]-1]+cycle[i][num[i]-2])%i;
			if (mark[cycle[i][num[i]-1]][v]){
				//printf("%d,%d\n",cycle[i][num[i]-1],v);
				break;
			}
			cycle[i][num[i]++]=v;
			mark[cycle[i][num[i]-2]][cycle[i][num[i]-1]]=true;
		}
		for (int j=0;j<num[i]-1;j++)
			mark[cycle[i][j]][cycle[i][j+1]]=false;
		num[i]--;
	}
}
int pow(unsigned long long a,unsigned long long b,int c){
	int ans=1;
	for (unsigned long long i=((unsigned long long)1)<<63;i>0;i>>=1){
		//printf("%llu\n",i);
		ans=(ans*ans)%c;
		if (b&i)
			ans=(ans*a)%c;
	}
	return ans;
}
int main()
{
	init();
	int cases;
	unsigned long long a,b;
	int c;
	scanf("%d",&cases);
	for (int t=1;t<=cases;t++){
		scanf("%llu %llu %d",&a,&b,&c);
		a%=num[c];
		printf("%d\n",cycle[c][pow(a,b,num[c])]);
	}
}
