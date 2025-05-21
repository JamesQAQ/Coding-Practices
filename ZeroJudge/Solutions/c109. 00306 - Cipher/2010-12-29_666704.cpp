#include <iostream>
using namespace std;

int main()
{
   string s;
   int len,n,k,a[201][200],num[201],b;
   while (cin>>n)
   {
      if (n==0)
         break;
      for (int i=1;i<=n;i++)
      {
         cin>>b;
         num[i]=2;
         a[i][0]=i;
         a[b][1]=i;
      }
      for (int i=1;i<=n;i++)
      {
         if (a[i][0]==a[i][1])
            num[i]=1;
         else
         {
            while (a[a[i][num[i]-1]][1]!=i)
            {
               a[i][num[i]]=a[a[i][num[i]-1]][1];
               num[i]++;
            }
         }
      }
      while (cin>>k)
      {
         if (k==0)
            break;
         getline(cin,s);
         len=s.length();
         for (int i=1;i<=n;i++)
         {
            if (a[i][k%num[i]]>=len)
               cout<<" ";
            else
               cout<<s[a[i][k%num[i]]];
         }
         cout<<endl;
      }
      cout<<endl;
   }
   return 0;
}
