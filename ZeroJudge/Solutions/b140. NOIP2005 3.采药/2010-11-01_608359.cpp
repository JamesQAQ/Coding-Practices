#include <iostream>
using namespace std;

int main()
{
   int c[101][1001],t,m,tim[101],p[101];
   while (cin>>t>>m)
   {
      for (int i=1;i<=m;i++)
         cin>>tim[i]>>p[i];
      c[0][0]=0;
      for (int i=1;i<=m;i++)
         for (int j=1;j<=t;j++)
         {
            if (tim[i]<=j)
            {
               if (p[i]+c[i-1][j-tim[i]]>c[i-1][j])
                  c[i][j]=p[i]+c[i-1][j-tim[i]];
               else
                  c[i][j]=c[i-1][j];
            }
            else
               c[i][j]=c[i-1][j];
         }
      cout<<c[m][t]<<endl;
   }
}
