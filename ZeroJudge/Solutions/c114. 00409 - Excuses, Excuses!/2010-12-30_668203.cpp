#include <iostream>
using namespace std;

int main()
{
    string key[20],ex[20],exx[20];
    int m,n,sum[20],maxx,t=0;
    while (cin>>m>>n)
    {
        for (int i=0;i<m;i++)
            cin>>key[i];
        getline(cin,ex[0]);
        for (int i=0;i<n;i++)
        {
            sum[i]=0;
            getline(cin,ex[i]);
            exx[i]=ex[i];
            for (int j=0;j<ex[i].length();j++)
                if (ex[i].at(j)<='Z'&&ex[i].at(j)>='A')
                    ex[i].at(j)+=32;
            ex[i].insert(0," ");
            ex[i]+=" ";
        }
        maxx=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                int p=ex[i].find(key[j]);
                while (p!=-1)
                {
                    char a=ex[i].at(p-1),b=ex[i].at(p+key[j].length());
                    if (!(a<='z'&&a>='a')&&!(b<='z'&&b>='a'))
                        sum[i]++;
                    p=ex[i].find(key[j],p+1);
                }
                if (sum[i]>maxx)
                    maxx=sum[i];
            }
        }
        cout<<"Excuse Set #"<<++t<<endl;
        for (int i=0;i<n;i++)
            if (sum[i]==maxx)
                cout<<exx[i]<<endl;
        cout<<endl;
    }
    return 0;
}
