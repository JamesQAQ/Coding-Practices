#include <iostream>
using namespace std;

int main()
{
    string s;
    int sum=0,k=0,n,math_control=0;
    while (getline(cin,s))
    {
        n=s.length();
        for (int i=0;i<n;i++)
        {
            if ((s[i]>=48)&&(s[i]<=57))
                k=k*10+s[i]-48;
            else if (s[i]==32)
            {
                if (math_control==0)
                    sum+=k;
                k=0;
                math_control=0;
            }
            else
                math_control=1;
        }
        if ((((s[n-1]>=48)&&(s[n-1]<=57))||(s[n-1]==32))&&(math_control==0))
            sum+=k;
        math_control=0;
        k=0;
        cout<<sum<<endl;
        sum=0;
    }
    //system("pause");
    return 0;
}
