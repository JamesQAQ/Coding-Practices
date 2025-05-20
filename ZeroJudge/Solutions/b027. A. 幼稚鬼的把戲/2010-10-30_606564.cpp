#include <iostream>
using namespace std;

int main()
{
    int n,m,num[14];
    bool unfair;
    char c;
    while (cin>>n)
    {
        cin>>m;
        if (n==0&&m==0)
            break;
        int sum=0;
        unfair=0;
        memset(num,0,sizeof(num));
        for (int i=0;i<m;i++)
        {
            cin>>c;
            if (c=='+')
            {
                cin>>c;
                if (c=='1')
                {
                    cin>>c;
                    num[10]++;
                    if (num[10]>4)
                        unfair=1;
                    sum+=10;
                }
                else
                {
                    num[12]++;
                    if (num[12]>4)
                        unfair=1;
                    sum+=20;
                }
            }
            else if (c=='-')
            {
                cin>>c;
                if (c=='1')
                {
                    cin>>c;
                    num[10]++;
                    if (num[10]>4)
                        unfair=1;
                    sum-=10;
                    if (sum<0)
                        sum=0;
                }
                else
                {
                    num[12]++;
                    if (num[12]>4)
                        unfair=1;
                    sum-=20;
                    if (sum<0)
                        sum=0;
                }
            }
            else if (c=='A')
            {
                sum=0;
                num[1]++;
                if (num[1]>4)
                    unfair=1;
            }
            else if (c=='4')
            {
                num[4]++;
                if (num[4]>4)
                    unfair=1;
            }
            else if (c=='5')
            {
                num[5]++;
                if (num[5]>4)
                    unfair=1;
            }
            else if (c=='J')
            {
                num[11]++;
                if (num[11]>4)
                    unfair=1;
            }
            else if (c=='K')
            {
                sum=99;
                num[13]++;
                if (num[13]>4)
                    unfair=1;
            }
            else
            {
                sum+=c-48;
                num[c-48]++;
                if (num[c-48]>4)
                    unfair=1;
            }
            if (sum>99)
                unfair=1;
        }
        if (unfair)
            cout<<"Unfair game"<<endl;
        else
            cout<<sum<<endl;
    }
    return 0;
}
