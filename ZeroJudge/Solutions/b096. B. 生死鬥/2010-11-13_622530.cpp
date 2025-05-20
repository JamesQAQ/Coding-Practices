#include <iostream>
using namespace std;

int main()
{
    int php,pa,pd,bhp,ba,bd;
    while (cin>>php>>pa>>pd>>bhp>>ba>>bd)
    {
        if (php==0&&pa==0&&pd==0&&bhp==0&&ba==0&&bd==0)
            break;
        if (pa-bd<=0)
            cout<<"You lose in "<<(php-1)/(ba-pd)+1<<" round(s)."<<endl;
        else if (ba-pd<=0)
            cout<<"You win in "<<(bhp-1)/(pa-bd)+1<<" round(s)."<<endl;
        else
        {
            int p=(bhp-1)/(pa-bd)+1;
            int b=(php-1)/(ba-pd)+1;
            if (p<=b)
                cout<<"You win in "<<p<<" round(s)."<<endl;
            else
                cout<<"You lose in "<<b<<" round(s)."<<endl;
        }
    }
    return 0;
}
