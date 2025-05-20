#include <iostream>
using namespace std;

short num[3],state[3][500][9],map[9];//0=draw,1=Owin,2=Xwin

void repeat(short x)
{
    int i,j;
    for (i=0;i<num[x];i++)
    {
        for (j=0;j<9;j++)
            if (state[x][i][j]!=map[j])
                break;
        if (j==9)
            return;
    }
    if (i==num[x])
    {
        for (int k=0;k<9;k++)
            state[x][num[x]][k]=map[k];
        num[x]++;
    }
    return;
}
bool test()
{
    for (int i=0;i<3;i++)
        if (map[i]==map[i+3]&&map[i+3]==map[i+6]&&map[i])
        {
            repeat(map[i]);
            return 1;
        }
    for (int i=0;i<9;i+=3)
        if (map[i]==map[i+1]&&map[i+1]==map[i+2]&&map[i])
        {
            repeat(map[i]);
            return 1;
        }
    if (map[0]==map[4]&&map[4]==map[8]&&map[4])
    {
        repeat(map[4]);
        return 1;
    }
    if (map[2]==map[4]&&map[4]==map[6]&&map[4])
    {
        repeat(map[4]);
        return 1;
    }
    return 0;
}
void dfs(short x)
{
    if (test())
        return;
    bool t=0;
    for (int i=0;i<9;i++)
        if (map[i]==0)
        {
            t=1;
            map[i]=x;
            int xx=(x==1)?2:1;
            dfs(xx);
            map[i]=0;
        }
    if (!t)
        repeat(0);
}
int main()
{
    string s;
    while (cin>>s)
    {
        int o=0,x=0;
        memset(num,0,sizeof(num));
        for (int i=0;i<9;i++)
        {
            if (s[i]=='-')
                map[i]=0;
            else if (s[i]=='O')
            {
                map[i]=1;
                o++;
            }
            else
            {
                map[i]=2;
                x++;
            }
        }
        if (o==x)
            dfs(1);
        else
            dfs(2);
        cout<<num[0]+num[1]+num[2]<<" "<<num[1]<<" "<<num[2]<<" "<<num[0]<<endl;
    }
    return 0;
}
