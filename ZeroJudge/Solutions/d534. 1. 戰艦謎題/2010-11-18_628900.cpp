#include <iostream>
#include <algorithm>
using namespace std;

int ans[24][4],sum[24][4],temp[4],num=0;
bool use[4]={};
void dfs(int x)
{
    if (x==4)
    {
        for (int i=0;i<4;i++)
            ans[num][i]=temp[i];
        sum[num][0]=ans[num][0]+ans[num][1];
        sum[num][1]=ans[num][2]+ans[num][3];
        sum[num][2]=ans[num][0]+ans[num][2];
        sum[num][3]=ans[num][1]+ans[num][3];
        num++;
        return;
    }
    for (int i=0;i<4;i++)
        if (!use[i])
        {
            use[i]=1;
            temp[x]=i;
            dfs(x+1);
            use[i]=0;
        }
}
int search(int a[])
{
    for (int i=0;i<num;i++)
    {
        int j;
        for (j=0;j<4;j++)
            if (sum[i][j]!=a[j])
                break;
        if (j==4)
            return i;
    }
    return -1;
}
int main()
{
    dfs(0);
    int a[4];
    while (cin>>a[0]>>a[1]>>a[2]>>a[3])
    {
        int p=search(a);
        if (p>-1)
            cout<<ans[p][0]<<" "<<ans[p][1]<<endl<<ans[p][2]<<" "<<ans[p][3]<<endl;
        else
            cout<<"No solutions."<<endl;
    }
    return 0;
}
