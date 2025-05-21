#include <iostream>
using namespace std;

int main()
{
    string s;
    long int sum=0,k=0;
    while (getline(cin,s))
    {
        long int n=s.length();
        for (long int i=0;i<n;i++)
        {
            if (s[i]!=32)
                k=k*10+s[i]-48;
            else
            {
                sum+=k;
                k=0;
            }
        }
        sum+=k;
        k=0;
        cout<<sum<<endl;
        sum=0;
    }
    //system("pause");
    return 0;
}
