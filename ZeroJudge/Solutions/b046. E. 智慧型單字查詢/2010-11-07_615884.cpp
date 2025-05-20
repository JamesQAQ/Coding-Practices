#include <iostream>
#include <sstream>
using namespace std;

int n,m,num,ans;
string s[1000],temp,t[4];
bool use[1000];
bool ok(int x)
{
    int len,p;
    string ss;
    for (int i=0;i<num;i++)
    {
        ss=t[i];
        len=ss.length();
        if (ss[0]=='*'&&ss[len-1]=='*')
        {
            ss=ss.substr(1,len-2);
            p=s[x].find(ss);
            if (p==-1)
                return 0;
        }
        else if (ss[0]=='*')
        {
            ss=ss.substr(1,len-1);
            len--;
            int slen=s[x].length();
            for (int i=0;i<len;i++)
                if (ss[len-i-1]!=s[x].at(slen-i-1))
                    return 0;
        }
        else if (ss[len-1]=='*')
        {
            ss=ss.substr(0,len-1);
            p=s[x].find(ss);
            if (p==-1||p!=0)
                return 0;
        }
    }
    return 1;
}
int main()
{
    while (cin>>n)
    {
        for (int i=0;i<n;i++)
            cin>>s[i];
        cin>>m;
        getline(cin,temp);
        for (int i=1;i<=m;i++)
        {
            for (int j=0;j<n;j++)
                use[j]=0;
            num=0;
            ans=0;
            getline(cin,temp);
            stringstream ss(temp);
            while (ss>>t[num])
                num++;
            for (int j=0;j<n;j++)
                if (ok(j))
                {
                    ans++;
                    use[j]=1;
                }
            cout<<"Query "<<i<<": "<<temp<<", "<<ans<<" item(s) is found."<<endl;
            for (int j=0;j<n;j++)
                if (use[j])
                    cout<<s[j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
