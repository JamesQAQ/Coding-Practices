#include <iostream>
using namespace std;

int main()
{
    string s;
    while (getline(cin,s))
    {
        int c=0;
        int n=s.length();
        for (int i=0;i<n;i++)
        {
            if ((s[i]>64&&s[i]<91)||(s[i]>96&&s[i]<123))
            {
               i++;
               while ((s[i]>64&&s[i]<91)||(s[i]>96&&s[i]<123)) 
                   i++;
               c++; 
            }
        }
        cout<<c<<endl;
    }
    system ("pause");
    return 0;
}
