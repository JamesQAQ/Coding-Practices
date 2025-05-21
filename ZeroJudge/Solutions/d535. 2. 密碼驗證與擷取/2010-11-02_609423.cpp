#include <iostream>
using namespace std;

string s;
int len;
bool testcycle()
{
   for (int i=0;i<len/2;i++)
      if (s[i]!=s[len-i-1])
         return 1;
   return 0;
}
bool testbig()
{
   for (int i=0;i<len-1;i++)
      if ((s[i]-48)*2<s[i+1]-48)
         return 1;
   return 0;
}
int main()
{
   while (cin>>s)
   {
      bool ok=0;
      len=s.length();
      if (testcycle())
      {
         cout<<"INCORRECT"<<endl;
         continue;
      }
      if (testbig())
      {
         cout<<"INCORRECT"<<endl;
         continue;
      }
      for (int i=0;i<len;i++)
         if (s[i]%2==0)
         {
            ok=1;
            cout<<s[i];
         }
      if (ok)
         cout<<endl;
      else
         cout<<"0"<<endl;
   }
   return 0;
}
