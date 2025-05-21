#include <iostream>
#include <deque>
using namespace std;

struct Node{int x,y,d;};
deque <Node> Q;
int main()
{
   int n,m,sum[52][52],step[52][52],sx,sy,ex,ey;
   bool map[52][52];
   while (cin>>n>>m)
   {
      for (int i=0;i<=n+1;i++)
         for (int j=0;j<=m+1;j++)
            map[i][j]=1;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            cin>>map[i][j];
            sum[i][j]=0;
            step[i][j]=2500;
         }
      cin>>sx>>sy>>ex>>ey;
      sx++;
      sy++;
      ex++;
      ey++;
      if (map[sx][sy])
      {
         cout<<"0"<<endl;
         continue;
      }
      Node a;
      Q.clear();
      a.x=sx;
      a.y=sy;
      a.d=0;
      sum[sx][sy]=1;
      step[sx][sy]=0;
      Q.push_back(a);
      while (Q.empty()==0)
      {
         a=Q.front();
         Q.pop_front();
         int x=a.x,y=a.y,d=a.d;
         if (x==ex&&y==ey)
            continue;
         if (d>=step[ex][ey])
            continue;
         if (!map[x+1][y])
            if (d<step[x+1][y])
            {
               sum[x+1][y]+=sum[x][y];
               sum[x+1][y]%=100000;
               if (step[x+1][y]>d+1)
               {
                  a.x=x+1;
                  a.y=y;
                  a.d=d+1;
                  step[x+1][y]=d+1;
                  Q.push_back(a);
               }
            }
         if (!map[x][y+1])
            if (d<step[x][y+1])
            {
               sum[x][y+1]+=sum[x][y];
               sum[x][y+1]%=100000;
               if (step[x][y+1]>d+1)
               {
                  a.x=x;
                  a.y=y+1;
                  a.d=d+1;
                  step[x][y+1]=d+1;
                  Q.push_back(a);
               }
            }
         if (!map[x-1][y])
            if (d<step[x-1][y])
            {
               sum[x-1][y]+=sum[x][y];
               sum[x-1][y]%=100000;
               if (step[x-1][y]>d+1)
               {
                  a.x=x-1;
                  a.y=y;
                  a.d=d+1;
                  step[x-1][y]=d+1;
                  Q.push_back(a);
               }
            }
         if (!map[x][y-1])
            if (d<step[x][y-1])
            {
               sum[x][y-1]+=sum[x][y];
               sum[x][y-1]%=100000;
               if (step[x][y-1]>d+1)
               {
                  a.x=x;
                  a.y=y-1;
                  a.d=d+1;
                  step[x][y-1]=d+1;
                  Q.push_back(a);
               }
            }
      }
      cout<<sum[ex][ey]<<endl;
   }
   return 0;
}
