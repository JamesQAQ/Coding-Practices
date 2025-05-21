#include <iostream>
using namespace std;

int main()
{
    string s;
    int sum=0;
    while (getline(cin,s))
    {
        int n=s.length();
        for (int i=0;i<n;i++)
        {
            if ((s[i]<=122)&&(s[i]>=97))
                sum+=s[i]-96;
            else if ((s[i]<=90)&&(s[i]>=65))
                sum+=s[i]-64;
            else if ((n==1)&&(s[0]==48))
                goto the_end2;
            else
            {
                cout<<"Fail"<<endl;
                goto the_end;
            }
        }
        cout<<sum<<endl;
        the_end:
        sum=0;
    }
    the_end2:
    //system("pause");
    return 0;
}
