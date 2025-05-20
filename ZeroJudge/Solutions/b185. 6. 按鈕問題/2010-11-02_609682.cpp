#include <iostream>
using namespace std;

int n,m,s[4][2]={{0,1},{1,0},{0,-1},{-1,0}},ans;
bool map[8][8],temp[8][8],ok;
void click(int x,int y)
{
   map[x][y]=(map[x][y])?0:1;
   for (int i=0;i<4;i++)
      map[x+s[i][0]][y+s[i][1]]=(map[x+s[i][0]][y+s[i][1]])?0:1;
}
void clickt(int x,int y)
{
   temp[x][y]=(temp[x][y])?0:1;
   for (int i=0;i<4;i++)
      temp[x+s[i][0]][y+s[i][1]]=(temp[x+s[i][0]][y+s[i][1]])?0:1;
}
bool test()
{
   for (int i=1;i<=m;i++)
      if (temp[n][i])
         return 0;
   return 1;
}
void dfs(int x,int sum)
{
   if (x==m)
   {
      for (int i=0;i<=n+1;i++)
         for (int j=0;j<=m+1;j++)
            temp[i][j]=map[i][j];
      for (int i=2;i<=n;i++)
         for (int j=1;j<=m;j++)
            if (temp[i-1][j])
            {
               clickt(i,j);
               sum++;
            }
      if (test())
      {
         ok=1;
         if (sum<ans)
            ans=sum;
      }
      return;
   }
   click(1,x+1);
   sum++;
   dfs(x+1,sum);
   click(1,x+1);
   sum--;
   dfs(x+1,sum);
}
int main()
{
   char c;
   while (cin>>n>>m)
   {
      ans=1024*1024;
      ok=0;
      memset(map,0,sizeof(map));
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            cin>>c;
            if (c=='O')
               map[i][j]=1;
            else
               map[i][j]=0;
         }
      click(1,1);
      dfs(1,1);
      click(1,1);
      dfs(1,0);
      if (ok)
         cout<<"Minimum Steps :"<<ans<<endl;
      else
         cout<<"Can not"<<endl;
   }
   return 0;
}
