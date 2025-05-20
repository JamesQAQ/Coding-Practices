#include <iostream>
#include <algorithm>
using namespace std;

string kind[5][5],itemname[40];
int kindnum[5]={1,2,2,5,2},colorvalue[100],charvalue[130],n,kindvalue[40][2],level[40];
char color[40];

void searchkind(int x,string s)
{
    for (int i=0;i<5;i++)
        for (int j=0;j<kindnum[i];j++)
            if (kind[i][j]==s)
            {
                kindvalue[x][0]=i;
                kindvalue[x][1]=j;
                return;
            }
}
bool cmp(int i,int j)
{
    if (kindvalue[i][0]>kindvalue[j][0]) return 1;
    if (kindvalue[i][0]<kindvalue[j][0]) return 0;
    if (kindvalue[i][1]>kindvalue[j][1]) return 1;
    if (kindvalue[i][1]<kindvalue[j][1]) return 0;
    if (colorvalue[color[i]]>colorvalue[color[j]]) return 1;
    if (colorvalue[color[i]]<colorvalue[color[j]]) return 0;
    if (kindvalue[i][0]==3&&!(kindvalue[i][1]==0||kindvalue[j][1]==0))
    {
        if (level[i]<level[j]) return 1;
        if (level[i]>level[j]) return 0;
    }
    int len=min(itemname[i].length(),itemname[j].length());
    for (int k=0;k<len;k++)
    {
        if (charvalue[itemname[i].at(k)]>charvalue[itemname[j].at(k)]) return 1;
        if (charvalue[itemname[i].at(k)]<charvalue[itemname[j].at(k)]) return 0;
    }
    return 0;
}
void printitem(int x)
{
    int len=itemname[x].length();
    bool big=0;
    for (int i=0;i<len;i++)
    {
        if (itemname[x].at(i)<='Z'&&itemname[x].at(i)>='A')
        {
            if (big)
            {
                cout<<itemname[x].at(i);
                return;
            }
            else
            {
                cout<<itemname[x].at(i);
                big=1;
            }
        }
    }
}
int main()
{
    //freopen("pg.in","r",stdin);
    //freopen("pgo.out","w",stdout);
    kind[0][0]="shoe";
    kind[1][0]="skirt";
    kind[1][1]="pant";
    kind[2][0]="cape";
    kind[2][1]="clothes";
    kind[3][0]="glove";
    kind[3][1]="targe";
    kind[3][2]="bastinado";
    kind[3][3]="bow";
    kind[3][4]="sword";
    kind[4][0]="earring";
    kind[4][1]="hat";
    colorvalue['W']=7;
    colorvalue['P']=6;
    colorvalue['B']=5;
    colorvalue['R']=4;
    colorvalue['Y']=3;
    colorvalue['G']=2;
    colorvalue['K']=1;
    colorvalue['U']=0;
    for (int i=0;i<26;i++)
    {
        charvalue[i+'A']=52-2*i+1;
        charvalue[i+'a']=52-2*i;
    }
    int cases,t[40];
    string temp;
    while (cin>>cases)
        while (cases-->0)
        {
            cin>>n;
            for (int i=0;i<n;i++)
            {
                t[i]=i;
                cin>>itemname[i]>>temp>>color[i]>>level[i];
                searchkind(i,temp);
            }
            stable_sort(t,t+n,cmp);
            int sum=0,firstkind=kindvalue[t[0]][0];
            for (int i=0;i<n;i++)
            {
                if (kindvalue[t[i]][0]!=firstkind)
                {
                    firstkind=kindvalue[t[i]][0];
                    if (sum!=0)
                    {
                        for (int j=sum;j<4;j++)
                            cout<<"__";
                        cout<<endl;
                    }
                    sum=0;
                }
                printitem(t[i]);
                sum++;
                if (sum==4)
                {
                    cout<<endl;
                    sum=0;
                }
            }
            if (sum!=0)
            {
                for (int i=sum;i<4;i++)
                    cout<<"__";
                cout<<endl;
            }
            cout<<"--------"<<endl;
        }
    return 0;
}
