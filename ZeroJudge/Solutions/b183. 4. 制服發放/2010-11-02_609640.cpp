#include <iostream>
using namespace std;

int n,m,num[6],l[30][2];
bool ok;
int test(string s)
{
   if (s[0]=='L')
      return 2;
   if (s[0]=='M')
      return 3;
   if (s[0]=='S')
      return 4;
   if (s[0]=='X')
   {
      if (s[1]=='X')
         return 0;
      if (s[1]=='L')
         return 1;
      if (s[1]=='S')
         return 5;
   }
}
void dfs(int x)
{
   if (x==m)
   {
      ok=1;
      return;
   }
   if (ok)
      return;
   for (int i=0;i<2;i++)
      if (num[l[x][i]]>0)
      {
         num[l[x][i]]--;
         dfs(x+1);
         num[l[x][i]]++;
      }
}
int main()
{
   string s;
   while (cin>>n>>m)
   {
      ok=0;
      n/=6;
      for (int i=0;i<6;i++)
         num[i]=n;
      for (int i=0;i<m;i++)
      {
         cin>>s;
         l[i][0]=test(s);
         cin>>s;
         l[i][1]=test(s);
      }
      dfs(0);
      if (ok)
         cout<<"YES"<<endl;
      else
         cout<<"NO"<<endl;
   }
   return 0;
}
