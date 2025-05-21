#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	string a,b;
	int fa[500]={},fb[500]={},ba[301]={},bb[301]={};
	while (cin>>a)
	{
		cin>>b;
		int la=a.length();
		int lb=b.length();
		int da=a.find('.');
		int db=b.find('.');
		int j=0;
		for (int i=da-1;i>=0;i--)
			fa[j++]=a[i]-48;
		j=300;
		for (int i=da+1;i<la;i++)
			ba[j--]=a[i]-48;
		j=0;
		for (int i=db-1;i>=0;i--)
			fb[j++]=b[i]-48;
		j=300;
		for (int i=db+1;i<lb;i++)
			bb[j--]=b[i]-48;
		for (int i=0;i<300;i++)
		{
			ba[i]+=bb[i];
			if (ba[i]>=10)
			{
				ba[i+1]+=ba[i]/10;
				ba[i]%=10;
			}
		}
		ba[300]+=bb[300];
		if (ba[300]>=10)
		{
			fa[0]+=ba[300]/10;
			ba[300]%=10;
		}
		if (ba[100]>=5)
			ba[101]++;
		for (int i=0;i<500;i++)
		{
			fa[i]+=fb[i];
			if (fa[i]>=10)
			{
				fa[i+1]+=fa[i]/10;
				fa[i]%=10;
			}
		}
		int y;//輸出小數點前 
		for (y=499;y>0;y--)
			if (fa[y]!=0)
			{
				printf("%d",fa[y]);
				break;
			}
		y--;
		for (;y>0;y--)
			printf("%d",fa[y]);
		printf("%d",fa[0]);
		printf(".");
		for (int i=300;i>=101;i--)
			printf("%d",ba[i]);
		printf("\n");
		memset(fa,0,sizeof(fa));
		memset(fb,0,sizeof(fb));
		memset(ba,0,sizeof(ba));
		memset(bb,0,sizeof(bb));
	}
	//system("pause");
	return 0;
}
