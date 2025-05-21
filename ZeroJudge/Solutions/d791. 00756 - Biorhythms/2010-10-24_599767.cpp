#include <iostream>
using namespace std;

int main()
{
    int p,e,i,d,c=0;
    while (cin>>p>>e>>i>>d)
    {
        if (p<0&&e<0&&i<0&&d<0)
            break;
        c++;
        while (p!=e)
        {
            while (p>e)
                e+=28;
            while (e>p)
                p+=23;
        }
        while (e!=i)
        {
            while (e>i)
                i+=33;
            while (i>e)
                e+=644;
        }
        if (i<=d)
            cout<<"Case "<<c<<": the next triple peak occurs in "<<i+21252-d<<" days."<<endl;
        else
            cout<<"Case "<<c<<": the next triple peak occurs in "<<i-d<<" days."<<endl;
    }
    return 0;
}
