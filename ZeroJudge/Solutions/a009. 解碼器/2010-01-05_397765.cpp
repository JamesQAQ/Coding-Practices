#include <iostream>
using namespace std;

int main()
{
   string s;
   while (getline(cin,s))
   {
      int n=s.length();
      for (int i=0;i<n;i++)
         s[i] -=7;
      cout<<s<<endl;
      s.clear();
   }
   system ("pause");
   return 0;
}
