#include <iostream>
using namespace std;

int main()
{
    int a,b,c,d,sum=0;
    while (cin>>a>>b>>c>>d)
    {
        if ((a==0)&&(b==0)&&(c==0)&&(d==0))
            break;
        sum+=(b<a)?a-b:40+a-b;
        sum+=(b<c)?c-b:40+c-b;
        sum+=(d<c)?c-d:40+c-d;
        cout<<sum*9+1080<<endl;
        sum=0;
    }
    //system("pause");
    return 0;
}
