#include <iostream>
using namespace std;

bool test(int x)
{
   for (int i=1;i*(i+1)+(i+1)*(i+2)+i*(i+2)<=x;i++)
      for (int j=i+1;i*j+j*(j+1)+i*(j+1)<=x;j++)
         for (int k=j+1;i*j+j*k+k*i<=x;k++)
            if (i*j+j*k+k*i==x)
               return 0;
   return 1;
}
int main()
{
   int ConvenientNumber[65],num=0;
   for (int i=1;;i++)
   {
      if (num==65)
         break;
      if (test(i))
         ConvenientNumber[num++]=i;
   }
   int x;
   while (cin>>x)
      cout<<ConvenientNumber[x-1]<<endl;
   return 0;
}
