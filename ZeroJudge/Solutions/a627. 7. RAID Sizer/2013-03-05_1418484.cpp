#include <cstdio>

int price[4]={75,110,140,250},sc[4]={250,400,500,750};
int main()
{
	int n,m;
	while (scanf("%d %d",&n,&m)==2){
		int mini=2147483647;
		int minpos;
		for (int i=0;i<4;i++){
			int num=(n-1)/sc[i]+1;
			if (m==5)
				num++;
			else if (m==1)
				num*=2;
			if (num<=8&&num*price[i]<mini){
				mini=num*price[i];
				minpos=i;
			}
		}
		int num=(n-1)/sc[minpos]+1;
		if (m==5)
			num++;
		else if (m==1)
			num*=2;
		printf("Qty: %d Disk: %dGB Price: $%d\n",num,sc[minpos],price[minpos]);
		printf("Total price of this %dGB array: $%d\n",((n-1)/sc[minpos]+1)*sc[minpos],num*price[minpos]);
	}
}

/*
450 1
1200 0
600 5
1300 1
3000 5
4500 5

250GB ($75), 400GB ($110), 500GB ($140), 750GB ($250)
*/
