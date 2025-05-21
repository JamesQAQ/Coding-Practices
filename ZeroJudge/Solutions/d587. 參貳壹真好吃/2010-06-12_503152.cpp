#include <iostream>
using namespace std;

int main()
{
    int a,n,n1=0,n2=0,n3=0;
    while (cin>>a)
    {
        for (int i=0;i<a;i++)
        {
            cin>>n;
            if (n==1)
                n1++;
            else if (n==2)
                n2++;
            else if (n==3)
                n3++;
        }
        for (int i=0;i<n1;i++)
            cout<<"1"<<" ";
        for (int i=0;i<n2;i++)
            cout<<"2"<<" ";
        for (int i=0;i<n3;i++)
            cout<<"3"<<" ";
        cout<<endl;
        n1=0;
        n2=0;
        n3=0;
    }
    //system ("pause");
    return 0;
}
