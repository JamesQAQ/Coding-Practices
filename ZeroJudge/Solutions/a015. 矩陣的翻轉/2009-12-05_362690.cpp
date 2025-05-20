#include <iostream>
using namespace std;

int main()
{
   int a,b;
   int c[100][100];
   while (cin>>a>>b)
   {
      for (int i=0;i<a;i++)
      {
         for (int j=0;j<b;j++)
            cin>>c[j][i];
      }
      for (int k=0;k<b;k++)
      {
         for (int l=0;l<a;l++)
            cout<<c[k][l]<<" ";
         cout<<endl;
      }
   }
   system("pause");
   return 0;
}
