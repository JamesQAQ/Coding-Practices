#include <iostream>
using namespace std;

int sum=0;
void count(int n);
int main()
{
    int n;
    while (cin>>n)
    {
        count(n);
        cout<<sum<<endl;
        sum=0;
    }
    //system ("pause");
    return 0;
}
void count(int n)
{
    int a;
    if (n!=0)
    {
        cin>>a;
        sum+=a;
        count(n-1);
    }
}
