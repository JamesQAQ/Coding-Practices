#include <iostream>
using namespace std;

int main()
{
    string a,b;
    while (cin>>a)
    {
        if (a[0]=='E')
            break;
        cin>>b;
        int n=a.length();
        if (n==1)
            cout<<"\"C\" can use printf(\"%d\",n); to show integer like "<<b<<"."<<endl;
        else if (n==3)
            cout<<"\"C++\" can use cout<<n; to show integer like "<<b<<"."<<endl;
        else if (n==4)
            cout<<"\"Java\" can use System.out.print(n); to show integer like "<<b<<"."<<endl;
        else if (n==6)
            cout<<"\"Pascal\" can use Write(n); to show integer like "<<b<<"."<<endl;
        else if (n==5)
            cout<<"\"Basic\" can use Print n to show integer like "<<b<<"."<<endl;
    }
    //system("pause");
    return 0;
}
