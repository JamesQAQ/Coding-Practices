#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string s;
    int a,temp,d,ans[1000][2],num,g;
    while (getline(cin,s))
    {
        if (s[0]=='0')
            break;
        stringstream ss(s);
        a=1;
        while (ss>>temp)
        {
            ss>>d;
            for (int i=0;i<d;i++)
                a*=temp;
        }
        a--;
        num=0;
        g=2;
        while (a!=1)
        {
            if (a%g==0)
            {
                ans[num][0]=g;
                ans[num][1]=1;
                a/=g;
                while (a%g==0)
                {
                    a/=g;
                    ans[num][1]++;
                }
                num++;
            }
            g++;
        }
        for (int i=num-1;i>=0;i--)
            cout<<ans[i][0]<<" "<<ans[i][1]<<" ";
        cout<<endl;
    }
    return 0;
}
