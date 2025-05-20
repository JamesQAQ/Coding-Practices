#include <iostream>
using namespace std;
int main()
{
    int x,i=0;
    while (cin>>x)
    {
        while (x>=5)  
        {
            i=i+x/5;
            x=x/5;
        } 
        cout<<i<<endl;
        i=0;
    }
    system("pause");
    return 0;
}
