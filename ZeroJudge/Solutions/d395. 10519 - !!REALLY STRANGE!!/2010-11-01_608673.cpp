#include <iostream>
using namespace std;

int main()
{
   string s;
   int a[101],ans[250];
   while (cin>>s)
   {
      int len=s.length();
      if (s[0]=='0'&&len==1)
      {
         cout<<"1"<<endl;
         continue;
      }
      for (int i=0;i<len;i++)
         a[len-i-1]=s[i]-48;
      for (int i=0;i<len+len+1;i++)
         ans[i]=0;
      for (int i=0;i<len;i++)
         for (int j=0;j<len;j++)
            ans[i+j]+=a[i]*a[j];
      for (int i=0;i<len;i++)
         ans[i]-=a[i];
      ans[0]+=2;
      for (int i=0;i<len+len+1;i++)
      {
         if (ans[i]>=10)
         {
            ans[i+1]+=ans[i]/10;
            ans[i]%=10;
         }
         else if (ans[i]<0)
         {
            ans[i+1]--;
            ans[i]+=10;
         }
      }
      int d;
      for (d=len+len;d>=0;d--)
         if (ans[d]!=0)
            break;
      for (;d>=0;d--)
         cout<<ans[d];
      cout<<endl;
   }
   return 0;
}
