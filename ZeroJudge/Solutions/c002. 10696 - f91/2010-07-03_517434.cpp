#include <iostream>
using namespace std;

int f91(int n);
int main()
{
    int n;
    while (cin>>n)
    {
        if (n==0)
            break;
        cout<<"f91("<<n;
        n=f91(n);
        cout<<") = "<<n<<endl;
    }
    //system("pause");
    return 0;
}
int f91(int n)
{
    while (1)
    {
    if (n<=100)
        n=f91(n+11);
    else if (n>=101)
        return n-10;
    }
}
