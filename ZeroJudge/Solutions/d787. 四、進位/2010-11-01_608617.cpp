#include <iostream>
using namespace std;

int main()
{
   int a[102],b[102],n;
   string sa,sb;
   while (cin>>n)
   {
      for (int k=0;k<n;k++)
      {
         int sum=0;
         cin>>sa>>sb;
         int lena=sa.length(),lenb=sb.length();
         int maxlen=max(lena,lenb);
         for (int i=0;i<n;i++)
         {
            a[i]=0;
            b[i]=0;
         }
         for (int i=0;i<lena;i++)
            a[lena-i-1]=sa[i]-48;
         for (int i=0;i<lenb;i++)
            b[lena-i-1]=sb[i]-48;
         for (int i=0;i<maxlen;i++)
            a[i]+=b[i];
         for (int i=0;i<maxlen;i++)
            if (a[i]>=10)
            {
               sum++;
               a[i+1]++;
               a[i]%=10;
            }
         cout<<sum<<endl;
      }
   }
   return 0;
}
