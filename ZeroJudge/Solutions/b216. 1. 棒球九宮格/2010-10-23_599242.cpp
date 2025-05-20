#include <iostream>
using namespace std;

int main()
{
    bool s[4][4];
    int a,b,edge,sum;
    while (cin>>a>>b)
    {
        edge=0;
        sum=0;
        memset(s,0,sizeof(s));
        if (a<=29&&a>=1&&b<=29&&b>=1&&a%10!=0&&b%10!=0)
        {
            for (int i=1;i<=3;i++)
                for (int j=1;j<=3;j++)
                    if (a<j*10&&a>(j-1)*10&&b<i*10&&b>(i-1)*10)
                        s[i][j]=1;
        }
        for (int i=0;i<8;i++)
        {
            cin>>a>>b;
            for (int i=1;i<=3;i++)
                for (int j=1;j<=3;j++)
                    if (a<j*10&&a>(j-1)*10&&b<i*10&&b>(i-1)*10)
                        s[i][j]=1;
        }
        for (int i=1;i<=3;i++)
        {
            if (s[i][1]&&s[i][2]&&s[i][3])
                edge++;
            if (s[1][i]&&s[2][i]&&s[3][i])
                edge++;
        }
        if (s[2][2])
            sum+=2;
        if (s[1][1])
            sum+=8;
        if (s[1][3])
            sum+=8;
        if (s[3][3])
            sum+=8;
        if (s[3][1])
            sum+=8;
        if (s[2][1])
            sum+=5;
        if (s[2][3])
            sum+=5;
        if (s[1][2])
            sum+=5;
        if (s[3][2])
            sum+=5;
        cout<<edge<<" "<<sum<<endl;
    }
    return 0;
}
