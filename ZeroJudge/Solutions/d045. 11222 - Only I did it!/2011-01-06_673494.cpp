#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    bool solve[10001][3];
    int no[3][1000],num[3],n,t=0,ans,ok[3];
    cin>>n;
    while (n-->0)
    {
        memset(solve,0,sizeof(solve));
        for (int i=0;i<3;i++)
        {
            cin>>num[i];
            for (int j=0;j<num[i];j++)
            {
                cin>>no[i][j];
                solve[no[i][j]][i]=1;
            }
        }
        for (int i=0;i<3;i++)
            ok[i]=0;
        ans=0;
        for (int i=0;i<3;i++)
        {
            stable_sort(no[i],no[i]+num[i]);
            int x=(i==0)?1:((i==1)?2:1);
            int y=(i==0)?2:0;
            for (int j=0;j<num[i];j++)
                if (!(solve[no[i][j]][x]||solve[no[i][j]][y]))
                    ok[i]++;
            if (ok[i]>ans)
                ans=ok[i];
        }
        cout<<"Case #"<<++t<<":\n";
        for (int i=0;i<3;i++)
            if (ok[i]==ans)
            {
                cout<<i+1<<" "<<ok[i]<<" ";
                int x=(i==0)?1:((i==1)?2:1);
                int y=(i==0)?2:0;
                for (int j=0;j<num[i];j++)
                    if (!(solve[no[i][j]][x]||solve[no[i][j]][y]))
                        cout<<no[i][j]<<" ";
                cout<<endl;
            }
    }
    return 0;
}
