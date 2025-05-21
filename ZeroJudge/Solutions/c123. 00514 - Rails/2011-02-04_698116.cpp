#include <iostream>
using namespace std;

int a[1000],stack[1000],n;
bool test()
{
    int at=0,next=2,h=1;
    stack[0]=1;
    while (next<=n)
    {
        if (stack[h-1]>a[at]&&h!=0)
            return 0;
        while (stack[h-1]==a[at]&&h!=0)
        {
            at++;
            h--;
        }
        while (stack[h-1]<a[at]&&h!=0)
            stack[h++]=next++;
        if (h==0)
            stack[h++]=next++;
    }
    while (h>0)
    {
        if (stack[h-1]!=a[at])
            return 0;
        h--;
        at++;
    }
    return 1;
}
int main()
{
    while (cin>>n)
    {
        if (n==0)
            break;
        while (cin>>a[0])
        {
            if (a[0]==0)
                break;
            for (int i=1;i<n;i++)
                cin>>a[i];
            cout<<((test())?"Yes":"No")<<endl;
        }
        cout<<endl;
    }
    return 0;
}
