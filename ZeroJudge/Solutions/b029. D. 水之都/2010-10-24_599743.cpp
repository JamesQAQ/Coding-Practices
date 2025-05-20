#include<iostream>
using namespace std;
int w[1000][1000];
int main(){
   int m,n;
   while(scanf("%d",&n)!=EOF){
      scanf("%d",&m);
      if(n==0&&m==0)break;
      int i,d[n],j,v[n];
      int c,b,k,a;
      for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                w[i][j]=0;
      for(i=0;i<n;i++)v[i]=0;
      for(j=0;j<m;j++){
         scanf("%d%d%d",&c,&b,&k);
         if(k>w[c-1][b-1]){
            w[c-1][b-1]=k;
            w[b-1][c-1]=k;
         }
      }
      int s,e;
      cin>>s>>e;
      v[s-1]=1;
      for(i=0;i<n;i++) d[i]=w[s-1][i];
      for(int k=0;k<n;k++){
         a=-1;
         int max=-1;
         for(i=0;i<n;i++){
            if(v[i]==0&&d[i]>max){
               max=d[i];
               a=i;
            }
         }
         if(a==-1)break;
         v[a]=1;
         for(i=0;i<n;i++){
            int x;
            x=min(d[a],w[a][i]);
            if(x>d[i])d[i]=x;
         }
      }
      printf("%d\n",d[e-1]);
   }
   return 0;
}
