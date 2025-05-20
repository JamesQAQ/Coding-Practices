#include <cstdio>

int main()
{
   int a[100000],maxx=1,n,temp=1;
   a[1]=2;
   while (scanf("%d",&n)==1){
      if (n>maxx)
         maxx=n;
      for (temp++;temp<=maxx;temp++)
         a[temp]=a[temp-1]+((temp-1)*temp+2)/2;
      temp--;
      printf("%d\n",a[n]);
   }
   return 0;
}
