#include <iostream>
using namespace std;

int main()
{
    int n,s,e,c[1440],id,a,b,d,temp,num[26],maxx,ans;
    char it;
    while (cin>>n)
    {
        cin>>s>>e;
        for (int i=0;i<26;i++)
            num[i]=0;
        for (int i=s;i<=e;i++)
            c[i]=0;
        maxx=0;
        ans=0;
        for (int i=0;i<n;i++)
        {
            cin>>id>>a>>b>>d;
            if (a<s)
                a=s;
            if (b>e)
                b=e;
            for (int j=a;j<=b;j++)
            {
                c[j]++;
                if (c[j]>maxx)
                    maxx=c[j];
            }
            for (int j=0;j<d;j++)
            {
                cin>>temp>>it;
                if (temp>=s&&temp<=e)
                {
                    num[it-'A']++;
                    if (num[it-'A']>ans)
                        ans=num[it-'A'];
                }
            }
        }
        cout<<maxx<<endl;
        if (maxx>0)
        {
            for (int i=s;i<=e;i++)
                if (c[i]==maxx)
                {
                    cout<<i<<" ";
                    while (c[i+1]==maxx)
                        i++;
                    cout<<i<<" ";
                }
        }
        cout<<endl;
        if (ans==0)
            cout<<"?"<<endl;
        else
        {
            for (int i=0;i<26;i++)
                if (num[i]==ans)
                    cout<<(it=i+'A')<<" ";
                cout<<endl;
        }
    }
    return 0;
}
