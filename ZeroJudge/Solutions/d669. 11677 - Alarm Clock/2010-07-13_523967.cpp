#include <iostream>
#include <stdio.h>
using namespace std;

int main ()
{
	int x1,x2,y1,y2,sum;
	while (scanf("%d",&x1)!=EOF)
	{
		scanf("%d%d%d",&y1,&x2,&y2);
		if ((x1==0)&&(y1==0)&&(x2==0)&&(y2==0))
			break;
		if (x1==0)
			x1=24;
		if (x2==0)
			x2=24;
		if ((x2>x1)||(x2==x1)&&(y2>=y1))
			sum=(x2-x1)*60+(y2-y1);
		else
			sum=1440-((x1-x2)*60+(y1-y2));
		printf("%d\n",sum);
	}
	//system("pause");
	return 0;
}
