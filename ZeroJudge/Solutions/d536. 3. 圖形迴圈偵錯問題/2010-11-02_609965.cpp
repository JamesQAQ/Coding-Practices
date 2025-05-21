#include <iostream>
using namespace std;

bool map[26][26],exist;
int ans,templen;
void dfs(int start,int now)
{
   if (templen>ans)
      return;
   if (map[now][start])
   {
      if (templen<ans)
        ans=templen;
      exist=1;
      return;
   }
   for (int i=0;i<26;i++)
      if (map[now][i])
      {
         map[now][i]=0;
         templen++;
         dfs(start,i);
         templen--;
         map[now][i]=1;
      }
}
int main()
{
   char a,b;
   int n;
   while (cin>>n)
   {
      exist=0;
      memset(map,0,sizeof(map));
      for (int i=0;i<n;i++)
      {
         cin>>a>>b;
         map[a-'A'][b-'A']=1;
      }
      ans=100000;
      templen=0;
      for (int i=0;i<26;i++)
      {
         templen++;
         dfs(i,i);
         templen--;
      }
      if (exist)
         cout<<ans<<endl;
      else
         cout<<"0"<<endl;
   }
   return 0;
}
