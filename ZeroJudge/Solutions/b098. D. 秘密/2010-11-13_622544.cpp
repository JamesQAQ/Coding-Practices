#include <iostream>
using namespace std;

int main()
{
    char s[53]={"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ"},ans[1001];
    int cases,k;
    while (cin>>cases)
        while (cases-->0)
        {
            cin>>k;
            cin>>ans;
            int len=strlen(ans);
            for (int i=0;i<len;i++)
                cout<<s[ans[i]-'A'+26-k];
            cout<<endl;
        }
    return 0;
}
