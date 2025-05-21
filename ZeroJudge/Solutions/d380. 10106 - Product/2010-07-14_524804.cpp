#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	string aa,bb;
	int a[300]={},b[300]={},res[600]={};
	while (cin>>aa>>bb)
	{
		int am=aa.length();
		int bm=bb.length();
		int j=0;
		for (int i=am-1;i>=0;i--)
			a[j++]=aa[i]-48;
		j=0;
		for (int i=bm-1;i>=0;i--)
			b[j++]=bb[i]-48;
		for (int i=0;i<am;i++)
			for (int j=0;j<bm;j++)
				res[i+j]+=a[i]*b[j];
		for (int i=0;i<am+bm-1;i++)
			if (res[i]>=10)
			{
				res[i+1]+=res[i]/10;
				res[i]%=10;
			}
		int y;
		for (y=am+bm;y>0;y--)
			if (res[y]!=0)
			{
				printf("%d",res[y]);
				break;
			}
		y--;
		for (;y>0;y--)
			printf("%d",res[y]);
		printf("%d\n",res[0]);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(res,0,sizeof(res));
	}
	//system("pause");
	return 0;
}
