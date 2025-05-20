#include <iostream>
using namespace std;

int compar(int a[9][9])
{
    for (int i=0;i<9;i++)
    {
        for (int j=0;j<9;j++)
        {
            for (int k=j+1;k<9;k++)
            {
                if (a[i][j]==a[i][k])
                    return 1;
            }
        }
    }
    for (int l=0;l<9;l++)
    {
        for (int m=0;m<9;m++)
        {
            for (int n=m+1;n<9;n++)
            {
                if (a[m][l]==a[n][l])
                    return 1;
            }
        }
    }
    for (int o=0;o<9;o +=3)
    {
        for (int p=0;p<9;p +=3)
        {
            for (int q=o;q<o+3;q++)
            {
                for (int r=p;r<p+3;r++)
                {
                    for (int s=o;s<o+3;s++)
                    {
                        for (int t=p;t<p+3;t++)
                        {
                            if (q==s&&r==t)
                                continue;
                            else if (a[q][r]==a[s][t])
                                return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
int main()
{
    int a[9][9];
    while (cin>>a[0][0])
    {
        for (int i=1;i<9;i++)
            cin>>a[0][i];
        for (int j=1;j<9;j++)
        {
            for (int k=0;k<9;k++)
               cin>>a[j][k];    
        }
        if (compar(a))
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
    }
    system ("pause");
    return 0;
}
