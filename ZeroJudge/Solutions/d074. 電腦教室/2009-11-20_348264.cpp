#include <iostream>
using namespace std;
int main()
{
    int n,max=0;
    while (cin>>n)
    {
        long s[n];
        for (int i=1;i<=n;i++)
        {
            cin>>s[i];
            if (s[i]>max)
                max=s[i];
        }
        cout<<max<<endl;
        max=0;
    }
    system("pause");
    return 0;
}
