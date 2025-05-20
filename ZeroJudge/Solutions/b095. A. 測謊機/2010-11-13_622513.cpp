#include <iostream>
using namespace std;

int main()
{
    int a,b,ans,wrong,temp;
    bool ok;
    while (cin>>a>>b)
    {
        ok=0;
        wrong=0;
        ans=max(a,b);
        for (int i=0;i<30;i++)
        {
            cin>>temp;
            if (temp!=0)
            {
                if (temp==ans&&wrong<3)
                    ok=1;
                else
                    wrong++;
            }
        }
        if (ok)
            cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;
    }
    return 0;
}
