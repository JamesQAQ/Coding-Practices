#include <iostream>
using namespace std;

int n,a[100],sum;
bool finish;
bool cmp(int i,int j)
{
   if (i>j)
      return 1;
   return 0;
}
void dfs(int x,int d)
{
   if (finish)
      return;
   if (d>sum)
      return;
   if (d==sum)
   {
      finish=1;
      return;
   }
   for (int i=x;i<n;i++)
      dfs(i+1,d+a[i]);
}
int main()
{
   int m;
   while (cin>>m>>n)
   {
      for (int i=0;i<m;i++)
      {
         sum=0;
         finish=0;
         for (int j=0;j<n;j++)
         {
            cin>>a[j];
            sum+=a[j];
         }
         if (sum%2!=0)
         {
            cout<<"No"<<endl;
            continue;
         }
         sum/=2;
         stable_sort(a,a+n,cmp);
         dfs(1,a[0]);
         if (finish)
            cout<<"Yes"<<endl;
         else
            cout<<"No"<<endl;
      }
   }
   return 0;
}
