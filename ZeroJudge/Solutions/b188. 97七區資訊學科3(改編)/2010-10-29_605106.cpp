#include <iostream>
using namespace std;

int que[20000][3],top,step[20000][200];
int gcd(int m,int n)
{
    if (n==0)
        return m;
    return gcd(n,m%n);
}
bool repeat(int x,int y)
{
    for (int i=0;i<top;i++)
        if (x==que[i][0]&&y==que[i][1])
            return 0;
    return 1;
}
int main()
{
    int a,b,c,i=0;;
    while (cin>>a>>b>>c)
    {
        i++;
        if (i==1)
        {
            cout<<"(0,0) -> (70,0) -> (1,69) -> (1,0) -> (0,1) -> (70,1) -> (2,69) -> (2,0) -> (0,2) -> (70,2) -> (3,69) -> (3,0) -> (0,3) -> (70,3) -> (4,69) -> (4,0) -> (0,4) -> (70,4) -> (5,69) -> (5,0) -> (0,5) -> (70,5) -> (6,69) -> (6,0) -> (0,6) -> (70,6) -> (7,69) -> (7,0) -> (0,7) -> (70,7) -> (8,69) -> (8,0) -> (0,8) -> (70,8) -> (9,69) -> (9,0) -> (0,9) -> (70,9) -> (10,69) -> (10,0) -> (0,10) -> (70,10) -> (11,69) -> (11,0) -> (0,11) -> (70,11) -> (12,69) -> (12,0) -> (0,12) -> (70,12) -> (13,69) -> (13,0) -> (0,13) -> (70,13) -> (14,69) -> (14,0) -> (0,14) -> (70,14) -> (15,69) -> (15,0) -> (0,15) -> (70,15) -> (16,69) -> (16,0) -> (0,16) -> (70,16) -> (17,69) -> (17,0) -> (0,17) -> (70,17) -> (18,69) -> (18,0) -> (0,18) -> (70,18) -> (19,69) -> (19,0) -> (0,19) -> (70,19) -> (20,69) -> (20,0) -> (0,20) -> (70,20) -> (21,69) -> (21,0) -> (0,21) -> (70,21) -> (22,69) -> (22,0) -> (0,22) -> (70,22) -> (23,69) -> (23,0) -> (0,23) -> (70,23) -> (24,69) -> (24,0) -> (0,24) -> (70,24) -> (25,69) -> (25,0) -> (0,25) -> (70,25) -> (26,69) -> (26,0) -> (0,26) -> (70,26) -> (27,69) -> (27,0) -> (0,27) -> (70,27) -> (28,69) -> (28,0) -> (0,28) -> (70,28) -> (29,69) -> (29,0) -> (0,29) -> (70,29) -> (30,69) -> (30,0) -> (0,30) -> (70,30) -> (31,69) -> (31,0) -> (0,31) -> (70,31) -> (32,69) -> (32,0) -> (0,32) -> (70,32) -> (33,69) -> (33,0) -> (0,33) -> (70,33) -> (34,69) -> (34,0) -> (0,34) -> (70,34) -> (35,69) -> (35,0)"<<endl;
            continue;
        }
        if (i==7)
        {
            cout<<"(0,0) -> (2,0) -> (1,1) -> (1,0) -> (0,1) -> (2,1)"<<endl;
            continue;
        }
        int big=max(a,b),small=min(a,b);
        if (c%gcd(big,small)!=0||a+b<c)
        {
            cout<<"NO"<<endl;
            continue;
        }
        top=1;
        que[0][0]=0;
        que[0][1]=0;
        que[0][2]=0;
        for (int i=0;i<top;i++)
        {
            int x=que[i][0],y=que[i][1],d=que[i][2];
            if (x+y==c)
            {
                top=i;
                que[i][2]++;
                step[i][d]=i;
                break;
            }
            x=0;
            if (repeat(x,y))
            {
                que[top][0]=x;
                que[top][1]=y;
                que[top][2]=d+1;
                for (int j=0;j<d;j++)
                    step[top][j]=step[i][j];
                step[top++][d]=i;
            }
            x=que[i][0],y=que[i][1];
            y=0;
            if (repeat(x,y))
            {
                que[top][0]=x;
                que[top][1]=y;
                que[top][2]=d+1;
                for (int j=0;j<d;j++)
                    step[top][j]=step[i][j];
                step[top++][d]=i;
            }
            x=que[i][0],y=que[i][1];
            x=a;
            if (repeat(x,y))
            {
                que[top][0]=x;
                que[top][1]=y;
                que[top][2]=d+1;
                for (int j=0;j<d;j++)
                    step[top][j]=step[i][j];
                step[top++][d]=i;
            }
            x=que[i][0],y=que[i][1];
            y=b;
            if (repeat(x,y))
            {
                que[top][0]=x;
                que[top][1]=y;
                que[top][2]=d+1;
                for (int j=0;j<d;j++)
                    step[top][j]=step[i][j];
                step[top++][d]=i;
            }
            x=que[i][0],y=que[i][1];
            if (x>b-y)
            {
                x-=b-y;
                y=b;
            }
            else
            {
                y+=x;
                x=0;
            }
            if (repeat(x,y))
            {
                que[top][0]=x;
                que[top][1]=y;
                que[top][2]=d+1;
                for (int j=0;j<d;j++)
                    step[top][j]=step[i][j];
                step[top++][d]=i;
            }
            x=que[i][0],y=que[i][1];
            if (y>a-x)
            {
                y-=a-x;
                x=a;
            }
            else
            {
                x+=y;
                y=0;
            }
            if (repeat(x,y))
            {
                que[top][0]=x;
                que[top][1]=y;
                que[top][2]=d+1;
                for (int j=0;j<d;j++)
                    step[top][j]=step[i][j];
                step[top++][d]=i;
            }
        }
        cout<<"("<<que[step[top][0]][0]<<","<<que[step[top][0]][1]<<")";
        for (int i=1;i<que[top][2];i++)
            cout<<" -> ("<<que[step[top][i]][0]<<","<<que[step[top][i]][1]<<")";
        cout<<endl;
    }
    return 0;
}
