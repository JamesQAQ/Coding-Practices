#include <iostream>
using namespace std;

int main()
{
    bool use[19];
    int ot[200],ow[200],n,mini,gt,gw,uw[19],people,goal,sum;
    string name[200];
    while (cin>>n)
    {
        if (n==0)
            break;
        memset(use,0,sizeof(use));
        mini=1800;
        for (int i=0;i<n;i++)
        {
            cin>>name[i]>>ot[i]>>ow[i];
            if (use[ot[i]+ow[i]])
            {
                if (ow[i]<uw[ot[i]+ow[i]])
                    uw[ot[i]+ow[i]]=ow[i];
            }
            else
            {
                uw[ot[i]+ow[i]]=ow[i];
                use[ot[i]+ow[i]]=1;
            }
        }
        goal=0;
        for (int i=1;i<=18;i++)
            if (use[i])
            {
                goal++;
                if (1800/i*(uw[i]+1)<mini)
                {
                    mini=1800/i*(uw[i]+1);
                    gt=i-uw[i];
                    gw=uw[i];
                }
            }
        sum=1;
        people=0;
        while (people!=goal)
        {
            sum+=gt-1;
            for (int i=0;i<=gw;i++)
            {
                people=0;
                for (int j=1;j<=18;j++)
                    if (use[j])
                    {
                        if (sum%j>=j-uw[j]||sum%j==0)
                            people++;
                    }
                if (people==goal)
                    break;
                sum++;
            }
        }
        for (int i=n-1;i>=0;i--)
            if (sum%(ot[i]+ow[i])==ot[i]||ow[i]==0)
            {
                cout<<name[i]<<" finally comes "<<sum<<" minutes later"<<endl;
                break;
            }
    }
    return 0;
}
