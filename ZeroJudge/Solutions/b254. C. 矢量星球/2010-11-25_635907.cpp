#include <iostream>
using namespace std;

int m,no[500][1000],num[500];
short v[500][1000];
int test()
{
    int sum,l,r;
    for (int i=1;i<m;i++)
        for (int j=0;j<i;j++)
        {
            sum=0;
            l=0;
            r=0;
            while (l<num[i]&&r<num[j])
            {
                if (no[i][l]==no[j][r])
                    sum+=v[i][l++]*v[j][r++];
                while (no[i][l]<no[j][r]) l++;
                while (no[i][l]>no[j][r]) r++;
            }
            if (sum!=0)
                return (i%2)?2:1;
        }
    return 0;
}
int main()
{
    int n;
    char c;
    while (cin>>n>>m)
    {
        if (n==0&&m==0)
            break;
        for (int i=0;i<m;i++)
        {
            cin>>num[i];
            for (int j=0;j<num[i];j++)
                cin>>no[i][j]>>c>>v[i][j];
        }
        int ans=test();
        if (ans==2)
            cout<<"Rofu"<<endl;
        else if (ans==1)
            cout<<"Yin"<<endl;
        else
            cout<<"Hakuna matata"<<endl;
    }
    return 0;
}
