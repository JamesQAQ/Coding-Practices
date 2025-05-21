#include <iostream>
#include <sstream>
using namespace std;

int main()
{
   string s;
   double sum1,sum2;
   while (getline(cin,s))
   {
      stringstream ss(s);
      sum1=0;
      sum2=0;
      int no;
      double num;
      char c;
      while (ss>>no)
      {
         ss>>c;
         ss>>num;
         if (no%2==1)
            sum1+=num;
         else
            sum2+=num;
      }
      cout<<sum1-sum2<<endl;
   }
   return 0;
}
