#include <cstdio>

int a[200000],b[200000];
int main()
{
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	while (n--){
		for (int i=0;i<m;i++)
			scanf("%d",&a[i]);
		for (int i=0;i<m;i++)
			scanf("%d",&b[i]);
		int ati=0,atj=0,ans=0;
		while (ati<m&&atj<m){
			while (ati<m&&a[ati]<b[atj])
				ati++;
			while (atj<m&&b[atj]<a[ati])
				atj++;
			if (ati<m&&atj<m&&a[ati]==b[atj])
				ans++,ati++,atj++;
		}
		printf("%d\n",ans);
	}
}
