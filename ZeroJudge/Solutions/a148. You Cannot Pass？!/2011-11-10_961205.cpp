#include <cstdio>

int main()
{
int n;
while (scanf("%d",&n)==1){
int sum=0,tmp;
for (int i=0;i<n;i++)
scanf("%d",&tmp),sum+=tmp;
if (sum>n*59) puts("no");
else puts("yes");
}
return 0;
}
