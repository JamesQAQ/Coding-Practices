#include <iostream>
using namespace std;
int main()
{
    int m,n;
    while (cin>>m>>n)
    {
    if ((m*2+n)%3==0)
        cout<<"普通"<<endl;
    else if ((m*2+n)%3==1)
        cout<<"吉"<<endl;
    else 
        cout<<"大吉"<<endl; 
    }
    system("pause");
    return 0;
}
