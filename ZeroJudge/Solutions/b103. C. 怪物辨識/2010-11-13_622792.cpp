#include <iostream>
using namespace std;

int main()
{
    int m,n,a,b,right,wrong;
    char ans[10][40][41],temp[40][41];
    bool ok;
    while (cin>>m>>n>>a>>b)
    {
        for (int i=0;i<m;i++)
            for (int j=0;j<b;j++)
                cin>>ans[i][j];
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<b;j++)
                cin>>temp[j];
            ok=0;
            for (int k=0;k<m;k++)
            {
                right=0;
                wrong=0;
                for (int l=0;l<b;l++)
                    for (int o=0;o<a;o++)
                        if (ans[k][l][o]!='-')
                        {
                            if (ans[k][l][o]==temp[l][o])
                                right++;
                            else
                                wrong++;
                        }
                if (right>=wrong*4)
                {
                    ok=1;
                    break;
                }
            }
            if (ok)
                cout<<"Y"<<endl;
            else
                cout<<"N"<<endl;
        }
    }
    return 0;
}
