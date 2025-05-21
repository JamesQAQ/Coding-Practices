#include <iostream>
using namespace std;

int main()
{
   int a[7],ans,temp;
   while (cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6])
   {
      if (a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0&&a[6]==0)
         break;
      ans=a[4]+a[5]+a[6];
      a[1]-=11*a[5];
      if (a[1]<0)
         a[1]=0;
      temp=20*a[4];
      if (a[2]*4>temp)
      {
         a[2]-=temp/4;
         temp=0;
      }
      else
      {
         temp-=a[2]*4;
         a[2]=0;
      }
      a[1]-=temp;
      if (a[1]<0)
         a[1]=0;
      ans+=(a[3])?(a[3]-1)/4+1:0;
      a[3]%=4;
      if (a[3]==3)
      {
         temp=9;
         if (a[2]>=1)
         {
            temp-=4;
            a[2]--;
         }
      }
      else if (a[3]==2)
      {
         temp=18;
         if (a[2]>3)
         {
            temp-=12;
            a[2]-=3;
         }
         else
         {
            temp-=a[2]*4;
            a[2]=0;
         }
      }
      else if (a[3]==1)
      {
         temp=27;
         if (a[2]>5)
         {
            temp-=20;
            a[2]-=5;
         }
         else
         {
            temp-=a[2]*4;
            a[2]=0;
         }
      }
      else
         temp=0;
      a[1]-=temp;
      if (a[1]<0)
         a[1]=0;
      ans+=(a[2])?(a[2]-1)/9+1:0;
      a[2]%=9;
      if (a[2]!=0)
         a[1]-=36-a[2]*4;
      if (a[1]<0)
         a[1]=0;
      ans+=(a[1])?(a[1]-1)/36+1:0;
      cout<<ans<<endl;
   }
   return 0;
}
