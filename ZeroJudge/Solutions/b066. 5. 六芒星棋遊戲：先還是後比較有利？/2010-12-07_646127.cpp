#include <iostream>
using namespace std;

int pow2[13]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096},take[24][2]={{0,2},{0,3},{1,2},{2,3},{3,4},{1,5},{2,5},{2,6},{3,6},{3,7},{4,7},{5,6},{6,7},{5,8},{5,9},{6,9},{6,10},{7,10},{7,11},{8,9},{9,10},{10,11},{9,12},{10,12}};
short state[8192];//1 win
bool b[13];
void dfs(int sum)
{
    state[sum]=0;
    for (int i=0;i<13;i++)
        if (b[i])
        {
            int sum2=sum-pow2[i];
            if (state[sum2]==2)
            {
                b[i]=0;
                dfs(sum2);
                b[i]=1;
            }
            if (state[sum2]==0)
                state[sum]=1;
        }
    for (int i=0;i<24;i++)
    {
        int x=take[i][0],y=take[i][1];
        if (b[x]&&b[y])
        {
            int sum2=sum-pow2[x]-pow2[y];
            if (state[sum2]==2)
            {
                b[x]=0;
                b[y]=0;
                dfs(sum2);
                b[x]=1;
                b[y]=1;
            }
            if (state[sum2]==0)
                state[sum]=1;
        }
    }
}
int main()
{
    state[0]=1;
    for (int i=1;i<8192;i++)
        state[i]=2;
    memset(b,1,sizeof(b));
    dfs(8191);
    int t,n;
    while (cin>>t)
    {
        while (t-->0)
        {
            cin>>n;
            cout<<state[n]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
