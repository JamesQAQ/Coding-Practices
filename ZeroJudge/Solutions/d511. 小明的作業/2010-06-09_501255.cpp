#include <iostream>
using namespace std;

int main()
{
    int a,b,c,k=0;
    while (cin>>a>>b>>c)
    {
        if ((a+b>c)&&(b+c>a)&&(c+a>b))
            k++;
        for (int i=0;i<4;i++)
        {
            cin>>a>>b>>c;
            if ((a+b>c)&&(b+c>a)&&(c+a>b))
                k++;
        }
        cout<<k<<endl;
        k=0;
    }
    //system("pause");
    return 0;
}
