#include <iostream>
using namespace std;

bool wrong (string a,string b)
{
    int len=a.length(),lenb=b.length();
    if (lenb<len)
        return 0;
    for (int i=0;i<len;i++)
        if (a[len-1-i]!=b[lenb-1-i])
            return 1;
    return 0;     
}
int main()
{
    int cases,n;
    string ans,temp,a,b;
    bool l,r;
    while (cin>>cases)
        for (int i=1;i<=cases;i++)
        {
            cout<<"DATA SET #"<<i<<":"<<endl;
            cin>>ans>>n;
            int p=ans.find("#");
            if (p==0)
            {
                b=ans.substr(1,ans.length()-1);
                l=0;
                r=1;
            }
            else if (p==ans.length()-1)
            {
                a=ans.substr(0,ans.length()-1);
                l=1;
                r=0;
            }
            else
            {
                a=ans.substr(0,p);
                b=ans.substr(p+1,ans.length()-p);
                l=1;
                r=1;
            }
            for (int i=0;i<n;i++)
            {
                cin>>temp;
                if (l)
                    if (temp.find(a)!=0)
                    {
                        cout<<"IMPOSSIBLE"<<endl;
                        continue;
                    }
                if (r)
                    if (wrong(b,temp))
                    {
                        cout<<"IMPOSSIBLE"<<endl;
                        continue;
                    }
                cout<<"POSSIBLE"<<endl;
                        
            }
        }
    return 0;
}
