#include <iostream>
using namespace std;

int main()
{
    int n,a[100],at;
    while (cin>>n)
    {
        at=0;
        for (int i=0;i<n;i++)
            cin>>a[i];
        for (int i=0;i<n;i++)
        {
            if (a[i]>=at+30)
                break;
            if (at>a[i])
                at+=5;
            else
                at=a[i]+5;
        }
        cout<<at+30<<endl;
    }
    return 0;
}
