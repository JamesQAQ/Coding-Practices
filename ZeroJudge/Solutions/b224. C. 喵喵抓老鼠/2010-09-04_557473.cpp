#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,len,num,p,step[100][100],q[10000][2],mini;
    char map[100][100];
    int s[4][2]={{0,1},
                {1,0},
                {0,-1},
                {-1,0}};
    string ss;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0)
            break;
        num=0;
        p=0;
        mini=10000;
        memset(step,0,sizeof(step));
        cin>>ss;
        len=ss.length();
        for (int i=0;i<len;i++)
            map[0][i]=ss[i];
        for (int i=1;i<n;i++)
            for (int j=0;j<len;j++)
                cin>>map[i][j];
        for (int i=0;i<n;i++)
            for (int j=0;j<len;j++)
                if (map[i][j]=='K')
                {
                    map[i][j]='#';
                    q[p][0]=i;
                    q[p][1]=j;
                    num++;
                    break;
                }
        while (num>0)
        {
            for (int z=0;z<4;z++)
            {
                if (map[q[p][0]+s[z][0]][q[p][1]+s[z][1]]=='.')
                {
                    map[q[p][0]+s[z][0]][q[p][1]+s[z][1]]='#';
                    step[q[p][0]+s[z][0]][q[p][1]+s[z][1]]=step[q[p][0]][q[p][1]]+1;
                    q[p+num][0]=q[p][0]+s[z][0];
                    q[p+num][1]=q[p][1]+s[z][1];
                    num++;
                }
                else if (map[q[p][0]+s[z][0]][q[p][1]+s[z][1]]=='@')
                {
                    map[q[p][0]+s[z][0]][q[p][1]+s[z][1]]='!';
                    step[q[p][0]+s[z][0]][q[p][1]+s[z][1]]=step[q[p][0]][q[p][1]]+1;
                }
            }
            num--;
            p++;
        }
        for (int i=0;i<n;i++)
            for (int j=0;j<len;j++)
                if (map[i][j]=='!')
                    if (step[i][j]<mini)
                        mini=step[i][j];
        if (mini<10000)
            printf("%d\n",mini);
        else
            printf("= =\"\n");
    }
    return 0;
}
