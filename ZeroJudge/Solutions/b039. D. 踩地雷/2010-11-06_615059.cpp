#include <iostream>
using namespace std;

char map[16][30],start[16][30];
int cases,m,n,bomb,flag,never,s[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
bool change;
void printf()
{
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
            cout<<map[i][j];
        cout<<endl;
    }
}
int countt(int x,int y,char c,char d)
{
    int sum=0;
    for (int i=0;i<8;i++)
    {
        int xx=x+s[i][0],yy=y+s[i][1];
        if (xx>=0&&xx<m&&yy>=0&&yy<n)
            if (map[xx][yy]==c||map[xx][yy]==d)
                sum++;
    }
    return sum;
}
void allclear()
{
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            if (map[i][j]=='_')
            {
                map[i][j]=countt(i,j,'*','F')+48;
                never--;
                change=1;
            }
}
void allflag()
{
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            if (map[i][j]=='*')
            {
                map[i][j]='F';
                never--;
                change=1;
            }
}
void flagg(int x,int y)
{
    for (int i=0;i<8;i++)
    {
        int xx=x+s[i][0],yy=y+s[i][1];
        if (xx>=0&&xx<m&&yy>=0&&yy<n)
            if (map[xx][yy]=='*')
            {
                map[xx][yy]='F';
                change=1;
                never--;
                flag++;
            }
    }
}
void open(int x,int y)
{
    for (int i=0;i<8;i++)
    {
        int xx=x+s[i][0],yy=y+s[i][1];
        if (xx>=0&&xx<m&&yy>=0&&yy<n)
            if (map[xx][yy]=='_')
            {
                map[xx][yy]=countt(xx,yy,'*','F')+48;
                change=1;
                never--;
            }
    }
}
bool wrong(int x,int y)
{
    for (int i=-2;i<=2;i++)
        for (int j=-2;j<=2;j++)
        {
            int xx=x+i,yy=y+j;
            if (xx>=0&&xx<m&&yy>=0&&yy<n)
                if (map[xx][yy]!='_'&&map[xx][yy]!='*'&&map[xx][yy]!='F'&&map[xx][yy]!='Y'&&map[xx][yy]!='X')
                    if (map[xx][yy]-48>countt(xx,yy,'F','X')+countt(xx,yy,'_','*'))
                        return 1;
        }
    return 0;
}
void test(int x,int y)
{
    for (int i=0;i<8;i++)
    {
        int xx=x+s[i][0],yy=y+s[i][1];
        if (xx>=0&&xx<m&&yy>=0&&yy<n)
            if (map[xx][yy]=='_'||map[xx][yy]=='*')
            {
                map[xx][yy]='X';
                for (int j=0;j<8;j++)
                {
                    int xxx=x+s[j][0],yyy=y+s[j][1];
                    if (xxx>=0&&xxx<m&&yyy>=0&&yyy<n)
                        if (map[xxx][yyy]=='_'||map[xxx][yyy]=='*')
                            map[xxx][yyy]='Y';
                }
                if (wrong(x,y))
                {
                    for (int j=0;j<8;j++)
                    {
                        int xxx=x+s[j][0],yyy=y+s[j][1];
                        if (xxx>=0&&xxx<m&&yyy>=0&&yyy<n)
                            if (map[xxx][yyy]=='Y')
                                map[xxx][yyy]=start[xxx][yyy];
                    }
                    map[xx][yy]=countt(xx,yy,'*','F')+48;
                    never--;
                    change=1;
                }
                else
                {
                    for (int j=0;j<8;j++)
                    {
                        int xxx=x+s[j][0],yyy=y+s[j][1];
                        if (xxx>=0&&xxx<m&&yyy>=0&&yyy<n)
                            if (map[xxx][yyy]=='Y')
                                map[xxx][yyy]=start[xxx][yyy];
                    }
                    map[xx][yy]=start[xx][yy];
                }
            }
    }
}
void game()
{
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
        {
            int ff=countt(i,j,'F','F');
            if (flag==bomb)
            {
                allclear();
                return;
            }
            else if (never==bomb-flag)
            {
                allflag();
                return;
            }
            else if (map[i][j]!='_'&&map[i][j]!='*'&&map[i][j]!='F')
            {
                if (map[i][j]-48-ff==countt(i,j,'_','*'))
                    flagg(i,j);
                else if (map[i][j]-48==ff)
                    open(i,j);
                else if (map[i][j]-48-1==ff)
                    test(i,j);
            }
        }
}
int main()
{
    while (cin>>cases)
    {
        for (int t=0;t<cases;t++)
        {
            bomb=0;
            flag=0;
            never=0;
            cin>>m>>n;
            for (int i=0;i<m;i++)
                for (int j=0;j<n;j++)
                {
                    cin>>map[i][j];
                    start[i][j]=map[i][j];
                    if (map[i][j]=='*')
                    {
                        bomb++;
                        never++;
                    }
                    if (map[i][j]=='_')
                        never++;
                }
            change=1;
            while (change)
            {
                change=0;
                game();
            }
            printf();
        }
    }
    return 0;
}
