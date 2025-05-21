#include <cstdio>

int n,a[10],num,sum,ans[1000];
char s[30000000];
void dfs(int x){
   if (x==sum){
      for (int i=0;i<sum;i++)
         s[num++]=ans[i]+48;
      s[num++]='\n';
      return;
   }
   for (int i=1;i<=n;i++)
      if (a[i]>0){
         a[i]--;
         ans[x]=i;
         dfs(x+1);
         a[i]++;
      }
}
int main()
{
   while (scanf("%d",&n)==1){
      sum=num=0;
      for (int i=1;i<=n;i++){
         scanf("%d",&a[i]);
         sum+=a[i];
      }
      dfs(0);
      s[num++]='\0';
      printf("%s",s);
   }
   return 0;
}
