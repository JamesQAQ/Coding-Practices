#include <iostream>
using namespace std;

int main()
{
    int c[101][101],lena,lenb,cases=0;
    string a,b;
    while (getline(cin,a))
    {
        cases++;
        if (a[0]=='#')
            break;
        getline(cin,b);
        lena=a.length();
        lenb=b.length();
        for (int i=0;i<=lena;i++)
            c[i][0]=0;
        for (int i=0;i<=lenb;i++)
            c[0][i]=0;
        for (int i=1;i<=lena;i++)
            for (int j=1;j<=lenb;j++)
            {
                if (a[i-1]==b[j-1])
                    c[i][j]=c[i-1][j-1]+1;
                else
                    c[i][j]=max(c[i-1][j],c[i][j-1]);
            }
        cout<<"Case #"<<cases<<": you can visit at most "<<c[lena][lenb]<<" cities."<<endl;
    }
    return 0;
}
