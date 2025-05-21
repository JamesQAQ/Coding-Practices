#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin>>n)
    {
        n=(n%2==0)?n:n-1;
        cout<<n<<endl;
    }
    //system ("pause");
    return 0;
}
