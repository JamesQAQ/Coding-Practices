#include <iostream>
using namespace std;

int main()
{
   string a,b;
   int i;
   while (cin>>a)
   {
   b="";
   for (i=a.length()-1;i>=0;i--)
   {
   b +=a.at(i);
   }
   if (b==a)
   cout<<"yes"<<endl;
   else
   cout<<"no"<<endl;
}

   system("pause");
   return 0;
}
