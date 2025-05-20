#include <iostream>
#include <stdio.h>
using namespace std;

string s,i,g;
void test()
{
    while (1)
    {
    cin>>i;
    if (i=="ADD")
    {
        cin>>g;
        s=s+g;
    }
    else if (i=="ADH")
    {
        cin>>g;
        s=g+s;
    }
    else if (i=="ERA")
    {
        int a,b;
        cin>>a>>b;
        s.erase(a-1,b-a+1);
    }
    else if (i=="SUB")
    {
        int a,b;
        cin>>a>>b;
        s.assign(s,a-1,b-a+1);
    }
    else if (i=="SPA")
    {
        int a;
        cin>>a;
        s.insert(a-1,"_");
    }
    else if (i=="END")
        return;
    cout<<s<<endl;
    }
}
int main()
{
    while (cin>>s)
        test();
    return 0;
}
