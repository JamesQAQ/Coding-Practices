#include <iostream>
#include <stdio.h>
using namespace std;

bool compar(int a[],int b[],int bm,int d)
{
	int i;
	for(i=1;i<=bm;i++)
    {
        if(a[bm+d-i]>b[bm-i])   return 1;
        if(a[bm+d-i]<b[bm-i])   return 0;
    }
    return 1;
}
int main()
{
	string aa,bb;
	char c;
	int a[300]={},b[300]={},res[600]={};
	while (cin>>aa>>c>>bb)
	{
		int am=aa.length();
		int bm=bb.length();
		int j=0;
		for (int i=am-1;i>=0;i--)
			a[j++]=aa[i]-48;
		j=0;
		for (int i=bm-1;i>=0;i--)
			b[j++]=bb[i]-48;
		if (c=='*')
		{
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
		else
		{
			int d=am-bm;
			for (int i=d;i>=0;i--)
				while (compar(a,b,bm,i))
				{
					res[i]++;
					for (int j=0;j<bm;j++)
					{
						if (a[j+i]<b[j])
						{
							a[j+i+1]-=1;
							a[j+i]+=10;
						}
						a[j+i]-=b[j];
					}
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
	}
	//system("pause");
	return 0;
}
