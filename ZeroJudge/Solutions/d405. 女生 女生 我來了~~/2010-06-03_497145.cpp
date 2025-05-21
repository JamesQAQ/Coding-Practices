#include <iostream>
using namespace std;

int main()
{
    int n,k,a,b;
    int m[5000],s[5000][30];
    while (cin>>n)
    {
        if (n==0)
            break;
        for (int i=0;i<n;i++)
        {
            cin>>m[i];
            for (int ii=0;ii<m[i];ii++)
                cin>>s[i][ii];
        }
        cin>>k;
        for (int i=0;i<k;i++)
        {
            cin>>a>>b;
            if ((a>n)||(b>m[a-1])||(a<=0)||(b<=0))
                cout<<"啊!!!抄錯第"<<i+1<<"號女生的班級座號了啦!!"<<endl;
            else if (s[a-1][b-1]>=90)
                cout<<"第"<<i+1<<"號女生  第"<<a<<"班的第"<<b<<"號  成績為"<<s[a-1][b-1]<<" 成績優"<<endl;
            else if (s[a-1][b-1]>=60)
                cout<<"第"<<i+1<<"號女生  第"<<a<<"班的第"<<b<<"號  成績為"<<s[a-1][b-1]<<endl;
            else if (s[a-1][b-1]>=0)
                cout<<"第"<<i+1<<"號女生  第"<<a<<"班的第"<<b<<"號  成績為"<<s[a-1][b-1]<<" 不及格呀~~"<<endl;
        }
    }
    //system("pause");
    return 0;
}
