#include <iostream>
using namespace std;

int main()
{
    int n,suma,sumb,lena,lenb;
    string a,b;
    while (cin>>n)
        while (n-->0)
        {
            cin>>a>>b;
            suma=0;
            sumb=0;
            lena=a.length();
            lenb=b.length();
            for (int i=0;i<lena;i++)
                if (a[i]=='O')
                    suma++;
            for (int i=0;i<lenb;i++)
                if (b[i]=='O')
                    sumb++;
            if (lenb>=5)
            {
                if (lena>lenb)
                {
                    if (suma-1==sumb)
                        cout<<"NO"<<endl;
                    else if (suma<sumb)
                        cout<<"B"<<endl;
                    else
                        cout<<"A"<<endl;
                }
                else if (suma>sumb)
                    cout<<"A"<<endl;
                else if (suma<sumb)
                    cout<<"B"<<endl;
                else
                    cout<<"NO"<<endl;
            }
            else
            {
                if (lena>lenb)
                {
                    if (suma-1==sumb)
                        cout<<"NO"<<endl;
                    if (suma-sumb>5-lenb)
                        cout<<"A"<<endl;
                    else if (sumb>suma)
                        cout<<"B"<<endl;
                }
                else
                {
                    if (suma-sumb>5-lenb)
                        cout<<"A"<<endl;
                    else if (sumb-suma>5-lenb)
                        cout<<"B"<<endl;
                    else
                        cout<<"NO"<<endl;
                }
            }
        }
    return 0;
}
