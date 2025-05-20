#include <iostream>
#include <algorithm>
using namespace std;

int w[10][10],n,d[10],to[10],ans[9][2],t[9];
bool use[10],o[10][10];
bool cmp(int i,int j)
{
   if (ans[i][0]<ans[j][0])
      return 1;
   if (ans[i][0]>ans[j][0])
      return 0;
   if (ans[i][1]<ans[j][1])
      return 1;
   return 0;
}
void update(int x)
{
   for (int i=0;i<n;i++)
      if (w[x][i]!=-1&&(d[i]>w[x][i]||d[i]==-1))
      {
         d[i]=w[x][i];
         to[i]=x;
      }
}
int main()
{
   int m,a,b;
   char temp;
   while (cin>>n>>m)
   {
      memset(o,0,sizeof(o));
      memset(w,-1,sizeof(w));
      for (int i=0;i<n;i++)
      {
         use[i]=1;
         d[i]=-1;
      }
      for (int i=0;i<m;i++)
      {
         cin>>temp>>a;
         cin>>temp>>b;
         cin>>w[a-1][b-1];
         w[b-1][a-1]=w[a-1][b-1];
         use[a-1]=0;
         use[b-1]=0;
         o[a-1][b-1]=1;
      }
      int dd=0;
      for (;dd<n;dd++)
         if (!use[dd])
            break;
      use[dd]=1;
      update(dd);
      int sum=0,num=0,l,r;
      for (int i=dd+1;i<n;i++)
      {
         int miniat=-1,mini=-1;
         for (int j=0;j<n;j++)
            if (!use[j])
               if (miniat==-1||(d[j]<mini&&d[j]!=-1))
               {
                  miniat=j;
                  mini=d[j];
               }
         if (miniat==-1)
            break;
         t[i-1]=i-1;
         l=min(to[miniat],miniat);
         r=max(to[miniat],miniat);
         if (o[l][r])
         {
            ans[num][0]=l;
            ans[num++][1]=r;
         }
         else
         {
            ans[num][0]=r;
            ans[num++][1]=l;
         }
         use[miniat]=1;
         sum+=mini;
         update(miniat);
      }
      stable_sort(t,t+num,cmp);
      for (int i=0;i<num;i++)
         cout<<"(W"<<ans[t[i]][0]+1<<" W"<<ans[t[i]][1]+1<<") ";
      cout<<endl<<sum<<endl;
   }
}
