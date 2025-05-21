#include <iostream>
using namespace std;

int n;
string s;
bool m[10][7]={{1,1,1,0,1,1,1}
              ,{0,0,1,0,0,1,0}
              ,{1,0,1,1,1,0,1}
              ,{1,0,1,1,0,1,1}
              ,{0,1,1,1,0,1,0}
              ,{1,1,0,1,0,1,1}
              ,{1,1,0,1,1,1,1}
              ,{1,0,1,0,0,1,0}
              ,{1,1,1,1,1,1,1}
              ,{1,1,1,1,0,1,1}};
void print(int x,char d)
{
    for (int i=0;i<x;i++)
        cout<<d;
}
void rprint(int d)
{
    for (int i=0;i<s.length();i++)
    {
        print(1,' ');
        print(n,((m[s[i]-48][d])?'-':' '));
        print(2,' ');
    }
    cout<<endl;
}
void cprint(int x,int y)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<s.length();j++)
        {
            print(1,((m[s[j]-48][x])?'|':' '));
            print(n,' ');
            print(1,((m[s[j]-48][y])?'|':' '));
            print(1,' ');
        }
        cout<<endl;
    }
}
int main()
{
    while (cin>>n>>s)
    {
        if (n==0)
            break;
        rprint(0);
        cprint(1,2);
        rprint(3);
        cprint(4,5);
        rprint(6);
    }
    return 0;
}
