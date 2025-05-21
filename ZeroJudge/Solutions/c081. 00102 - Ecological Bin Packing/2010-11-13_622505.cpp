#include <iostream>
using namespace std;

int a[3][3],mini;
char temp[3],b[4]={"BCG"},ans[3];
bool use[3];
void dfs(int x,int sum)
{
    if (x==3)
    {
        if (sum<mini)
        {
            mini=sum;
            for (int i=0;i<3;i++)
                ans[i]=temp[i];
        }
        return;
    }
    for (int i=0;i<3;i++)
        if (!use[i])
        {
            use[i]=1;
            temp[x]=b[i];
            int p=0;
            for (int j=0;j<3;j++)
                if (j!=x)
                    p+=a[j][i];
            dfs(x+1,sum+p);
            use[i]=0;
        }
}
int main()
{
    while (cin>>a[0][0])
    {
        mini=2147483647;
        cin>>a[0][2]>>a[0][1];
        for (int i=1;i<3;i++)
            cin>>a[i][0]>>a[i][2]>>a[i][1];
        memset(use,0,sizeof(use));
        dfs(0,0);
        for (int i=0;i<3;i++)
            cout<<ans[i];
        cout<<" "<<mini<<endl;
    }
    return 0;
}
