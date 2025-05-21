#include <iostream>
using namespace std;

int main()
{
    string s;
    int count[1000]={0};
    int n,c=0,k=0;
    while (getline(cin,s))
    {
        n=s.length();
        for (int i=0;i<n;i++)
        {
            if (s[i]==32)
            {
                count[c]+=k;
                c++;
                k=0;
            }
            else if ((s[i]>=37)&&(s[i]<=47))
            {
                if (s[i]==37)
                    count[c-2]%=count[c-1];
                else if (s[i]==42)
                    count[c-2]*=count[c-1];
                else if (s[i]==43)
                    count[c-2]+=count[c-1];
                else if (s[i]==45)
                    count[c-2]-=count[c-1];
                else
                    count[c-2]/=count[c-1];
                count[c-1]=0;
                c--;
                i++;
            }
            else
                k=k*10+s[i]-48;
        }
        cout<<count[0]<<endl;
        count[0]=0;
        c=0;
    }
    //system("pause");
    return 0;
}
