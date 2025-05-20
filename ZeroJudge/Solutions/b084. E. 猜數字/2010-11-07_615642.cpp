#include <iostream>
using namespace std;

int aa[5040][4],num=0,temp[4];
bool use[10]={},ok[5040];
void dfs(int x)
{
    if (x==4)
    {
        for (int i=0;i<4;i++)
            aa[num][i]=temp[i];
        num++;
        return;
    }
    for (int i=0;i<10;i++)
        if (!use[i])
        {
            temp[x]=i;
            use[i]=1;
            dfs(x+1);
            use[i]=0;
        }
}
int main()
{
    dfs(0);
    int t,n;
    string s1,s2;
    while (cin>>t)
    {
        for (int i=0;i<t;i++)
        {
            int ans=5040;
            memset(ok,1,sizeof(ok));
            cin>>n;
            for (int j=0;j<n;j++)
            {
                cin>>s1>>s2;
                int ca=s2[0]-48,cb=s2[2]-48;
                for (int k=0;k<5040;k++)
                    if (ok[k])
                    {
                        int a=0,b=0;
                        for (int l=0;l<4;l++)
                            if (aa[k][l]==s1[l]-48)
                                a++;
                        if (a!=ca)
                        {
                            ok[k]=0;
                            ans--;
                            continue;
                        }
                        for (int l=0;l<4;l++)
                            for (int m=0;m<4;m++)
                                if (aa[k][l]==s1[m]-48&&l!=m)
                                    b++;
                        if (b!=cb)
                        {
                            ok[k]=0;
                            ans--;
                            continue;
                        }
                    }
            }
            if (ans)
                cout<<ans<<endl;
            else
                cout<<"You Cheat!"<<endl;
        }
    }
    return 0;
}
