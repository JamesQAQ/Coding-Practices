#include <iostream>
using namespace std;

int main()
{
    string a,b,d[51][51];
    while (cin>>a>>b)
    {
        int lena=a.length(),lenb=b.length();
        for (int i=0;i<=lena;i++)
            d[i][0].clear();
        for (int i=0;i<=lenb;i++)
            d[0][i].clear();
        for (int i=1;i<=lena;i++)
            for (int j=1;j<=lenb;j++)
            {
                if (a[i-1]==b[j-1])
                    d[i][j]=d[i-1][j-1]+a[i-1];
                else
                    d[i][j]=(d[i-1][j].length()>d[i][j-1].length())?d[i-1][j]:d[i][j-1];
            }
        if (d[lena][lenb].length()==0)
            cout<<"E"<<endl;
        else
            cout<<d[lena][lenb]<<endl;
    }
    return 0;
}
