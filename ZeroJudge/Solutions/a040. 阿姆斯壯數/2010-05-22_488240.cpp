#include <iostream>
using namespace std;

int ten(int c);
int main()
{
    int n,m,chi,tenn,one,one_one,all=0,c=0;
    while (cin>>n>>m)
    {
        for (int iii=n;iii<=m;iii++)
        {
            int ii=iii;
            for (int i=6;i>=0;i--)
            {
                tenn=ten(i);
                if (ii/tenn>0)
                {
                    chi=i+1;
                    break;
                }
            }
            for (int i=chi;i>0;i--)
            {
                tenn=ten(i-1);
                one=ii/tenn;
                one_one=one;
                ii%=tenn;
                for (int o=1;o<chi;o++)
                {
                    one*=one_one;
                }
                all+=one;
            }
            if (all==iii)
            {
                cout<<all<<" ";
                c++;
            }
            all=0;
        }
        if (c==0)
            cout<<"none"<<endl;
        else
            cout<<endl;
        c=0;
    }
    //system("pause");
    return 0;
}

int ten(int c)
{
    int ten=1;
    for (int i=0;i<c;i++)
    {
        ten*=10;
    }
    return ten;
}
