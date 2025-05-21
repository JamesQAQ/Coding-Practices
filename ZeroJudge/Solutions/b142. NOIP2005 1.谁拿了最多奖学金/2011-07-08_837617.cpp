#include <cstdio>
#include <cstring>

int main()
{
	int n,ans,sum,scorea,scoreb,all,t;
	char ansname[21],s[21],c1,c2;
	while (scanf("%d",&n)==1){
		all=0;
		ans=-1;
		for (int i=0;i<n;i++){
			scanf("%s %d %d %c %c %d",s,&scorea,&scoreb,&c1,&c2,&t);
			sum=0;
			if (scorea>80&&t>=1)
				sum+=8000;
			if (scorea>85&&scoreb>80)
				sum+=4000;
			if (scorea>90)
				sum+=2000;
			if (scorea>85&&c2=='Y')	
				sum+=1000;
			if (scoreb>80&&c1=='Y')
				sum+=850;
			if (sum>ans){
				ans=sum;
				strcpy(ansname,s);	
			}
			all+=sum;
		}
		printf("%s\n%d\n%d\n",ansname,ans,all);
	}
	return 0;
}
