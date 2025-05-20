#include <iostream>
#include <algorithm>
using namespace std;

string name[100000],a[100000],b[100000];
int n;
int main()
{
    string temp;
    while (cin>>n)
    {
        if (n==0)
            break;
        for (int i=0;i<n;i++)
        {
            cin>>name[i]>>a[i];
            b[i]=a[i];
        }
        stable_sort(b,b+n);
        temp=b[n/3-1];
        cout<<"LIST START"<<endl;
        for (int i=0;i<n;i++)
            if (a[i]<=temp)
                cout<<name[i]<<endl;
        cout<<"LIST END"<<endl;
    }
    return 0;
}
