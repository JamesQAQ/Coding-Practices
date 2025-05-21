#include <iostream>
using namespace std;

int m,n,ss[4][2]={{1,0},{0,-1},{-1,0},{0,1}},v[26];
char cc[4];
bool spot[51][51]={};
bool test(int x,int y,int d,string s)
{
    int len=s.length();
    for (int i=0;i<len;i++)
    {
        if (s[i]=='F')
        {
            x+=ss[d][0];
            y+=ss[d][1];
            if (x>m||y>n||x<0||y<0)
            {
                if (spot[x-ss[d][0]][y-ss[d][1]])
                {
                    x-=ss[d][0];
                    y-=ss[d][1];
                    continue;
                }
                cout<<x-ss[d][0]<<" "<<y-ss[d][1]<<" "<<cc[d];
                spot[x-ss[d][0]][y-ss[d][1]]=1;
                return 1;
            }
        }
        else if (s[i]=='R')
            d=(d+1)%4;
        else if (s[i]=='L')
            d=(d)?d-1:3;
    }
    cout<<x<<" "<<y<<" "<<cc[d];
    return 0;
}
int main()
{
    v['E'-'A']=0;
    v['S'-'A']=1;
    v['W'-'A']=2;
    v['N'-'A']=3;
    cc[0]='E';
    cc[1]='S';
    cc[2]='W';
    cc[3]='N';
    cin>>m>>n;
    int a,b,c;
    char temp;
    string s;
    while (cin>>a>>b>>temp)
    {
        c=v[temp-'A'];
        cin>>s;
        if (test(a,b,c,s))
            cout<<" LOST";
        cout<<endl;
    }
    return 0;
}
