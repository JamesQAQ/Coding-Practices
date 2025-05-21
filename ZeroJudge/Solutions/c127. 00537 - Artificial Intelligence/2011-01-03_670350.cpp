#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);
    char aa,bb,temp;
    string s,a,b;
    double c,d,e[33];
    int n,t=0,aat,bat;
    e[0]=1000000;
    e['k'-'M']=1000;
    e['m'-'M']=0.001;
    cin>>n;
    getline(cin,s);
    while (n-->0)
    {
        getline(cin,s);
        stringstream ss(s);
        a.clear();
        while (ss>>b)
            if (b.find("=")!=-1)
            {
                if (a.length()==0)
                    a=b;
                else
                    break;
            }
        stringstream s1(a);
        stringstream s2(b);
        s1>>aa>>temp>>c;
        s2>>bb>>temp>>d;
        for (aat=0;aat<a.length();aat++)
            if (a[aat]=='A'||a[aat]=='W'||a[aat]=='V')
                break;
        if (aat==a.length())
            aat--;
        for (bat=0;bat<b.length();bat++)
            if (b[bat]=='A'||b[bat]=='W'||b[bat]=='V')
                break;
        if (bat==b.length())
            bat--;
        if (a[aat-1]>57)
            c*=e[a[aat-1]-'M'];
        if (b[bat-1]>57)
            d*=e[b[bat-1]-'M'];
        cout<<"Problem #"<<++t<<endl;
        if (aa!='U'&&bb!='U')
        {
            if (aa=='P')
                cout<<"U="<<c/d<<"V\n";
            else
                cout<<"U="<<d/c<<"V\n";
        }
        else if (aa!='I'&&bb!='I')
        {
            if (aa=='P')
                cout<<"I="<<c/d<<"A\n";
            else
                cout<<"I="<<d/c<<"A\n";
        }
        else
            cout<<"P="<<c*d<<"W\n";
        cout<<endl;
    }
    return 0;
}
