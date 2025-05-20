#include <iostream>
using namespace std;

int main()
{
    int n,s,d;
    while (cin>>n)
    {
        for (int i=0;i<n;i++)
        {
            cin>>s>>d;
            if (d>s)
                cout<<"impossible"<<endl;
            else if ((s+d)%2==1)
                cout<<"impossible"<<endl;
            else
                cout<<(s+d)/2<<" "<<(s-d)/2<<endl;
        }
    }
    //system("pause");
    return 0;
}
