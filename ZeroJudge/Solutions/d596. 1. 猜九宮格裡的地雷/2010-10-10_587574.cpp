#include <iostream>
using namespace std;

bool a[5][5],f;
int s[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void spread(int x,bool c)
{
    int xx,yy;
    xx=x/3+1;
    yy=x%3+1;
    for (int i=0;i<4;i++)
        a[xx+s[i][0]][yy+s[i][1]]=c;
}
int main()
{
    int n,x;
    while (cin>>n)
    {
    for (int i=0;i<n;i++)
    {
        f=0;
        memset(a,0,sizeof(a));
        cin>>x;
        spread(x-1,1);
        cin>>x;
        spread(x-1,0);
        cin>>x;
        spread(x-1,0);
        for (int i=1;i<=3;i++)
            for (int j=1;j<=3;j++)
                if (a[i][j])
                {
                    if (!f)
                    {
                        cout<<(i-1)*3+j;
                        f=1;
                    }
                    else
                        cout<<" "<<(i-1)*3+j;
                }
        if (!f)
            cout<<"Empty"<<endl;
        else
            cout<<endl;           
    }
}
    return 0;
}
