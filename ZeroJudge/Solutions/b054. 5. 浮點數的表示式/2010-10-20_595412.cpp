#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
   double a,value;
   bool c[32];
   int b[4];
   while (cin>>value)
   {
      a=fabs(value);
      memset(c,0,sizeof(c));
      memset(b,0,sizeof(b));
      if (value<0)
         c[8]=1;
      int z=1;
      if (a>=2)
         while (a>=2)
         {
            a/=2;
            z++;
         }
      else
         while (a<1)
         {
            a*=2;
            z--;
         }
      a-=1;
      int zz=abs(z),d=7;
      c[0]=1;
      while (zz>=1)
      {
         c[d--]=zz%2;
         zz/=2;
      }
      if (z<0)
      {
         d=7;
         for (;d>=0;d--)
            if (c[d])
               break;
         d--;
         for (;d>=0;d--)
            c[d]=(c[d])?0:1;
      }
      for (int i=9;i<=31;i++)
      {
         a*=2;
         if (a>=1)
         {
            c[i]=1;
            a-=1;
         }
         if (a==0)
            break;
      }
      cout<<"Input a value: "<<value<<endl;
      cout<<"Exponent lst byte 2nd byte 3rd byte"<<endl;
      cout<<"Memory Contents= ";
      for (int i=0;i<4;i++)
      {
         for (int j=0;j<8;j++)
         {
            cout<<c[i*8+j];
            b[i]=b[i]*2+c[i*8+j];
         }
         cout<<" ";
      }
      cout<<endl;
      printf("<&H%02X>   <&H%02X>   <&H%02X>   <&H%02X>\n",b[0],b[1],b[2],b[3]);
      cout<<"FLOATING POINT FORMAT => ";
      if (c[8])
         cout<<"-";
      cout<<"0.1";
      for (int i=9;i<32;i++)
         cout<<c[i];
      cout<<" * 2 ^ "<<z<<endl;
      cout<<"Floating Point Value = "<<value<<endl;
      cout<<"================================================================="<<endl;      
   }
   return 0;
}
