#include <iostream>
using namespace std;

int main()
{
   int t,n;
   cout.setf(ios::fixed);
   cout.precision(2);
   while (cin>>t)
   {
      for (int i=0;i<t;i++)
      {
         cin>>n;
         double sum=0;
         int temp;
         for (int j=0;j<n;j++)
         {
            cin>>temp;
            sum+=temp;
         }
         cout<<sum/n<<endl;
      }
   }
}
