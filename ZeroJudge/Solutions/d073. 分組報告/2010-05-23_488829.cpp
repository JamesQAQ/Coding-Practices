#include <iostream>
using namespace std;

int main()
{
    int a;
    while(cin>>a)
    {
        a=(a%3==0)?a/3:a/3+1;
        cout<<a<<endl;
    }
    //system("pause");
    return 0;
}
