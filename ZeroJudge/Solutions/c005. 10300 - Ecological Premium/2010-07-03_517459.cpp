#include <iostream>
using namespace std;

int main()
{
    long long int n,f,a,b,c,sum=0;
    while (cin>>n)
    {
        for (long long int i=0;i<n;i++)
        {
            cin>>f;
            for (long long int o=0;o<f;o++)
            {
                cin>>a>>b>>c;
                sum+=a*c;
            }
            cout<<sum<<endl;
            sum=0;
        }
    }
    //system("pause");
    return 0;
}
