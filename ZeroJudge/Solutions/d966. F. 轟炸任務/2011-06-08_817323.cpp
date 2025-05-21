#include <cstdio>
#include <vector>

int h,w,k,stack[400],top,num,scc[400];
std::vector <int> path[400],rpath[400];
bool v[400];
void dfs(int x){
   v[x]=true;
   int p=path[x].size();
   for (int i=0;i<p;i++)
      if (!v[path[x][i]])
         dfs(path[x][i]);
   stack[top++]=x;   
}
bool rdfs(int x){
   v[x]=true;
   scc[x]=num;
   if (x>=h+w){
      if (scc[x]==scc[x-h-w])
         return false;
   }
   else{
      if (scc[x]==scc[x+h+w])
         return false;
   }
   int p=rpath[x].size();
   for (int i=0;i<p;i++){
      int to=rpath[x][i];
      if (!v[to]){
         if (!rdfs(to))
            return false;
      }
   }
   return true;
}
bool ok(){
   top=0;
   for (int i=0;i<2*(h+w);i++)
      if (!v[i])
         dfs(i);
   num=0;
   for (int i=0;i<2*(h+w);i++)
      v[i]=false,scc[i]=-1;
   while (top>0){
      if (!v[stack[top-1]])
         if (!rdfs(stack[top-1]))
            return false;
      top--,num++;
   }
   return true;
}
int main(){
   int cases,x,y,s;
   while (scanf("%d",&cases)==1)
      while (cases--){
         scanf("%d %d %d",&h,&w,&k);
         for (int i=0;i<2*(h+w);i++)
            path[i].clear(),rpath[i].clear(),v[i]=false;
         for (int i=0;i<k;i++){
            scanf("%d %d %d",&x,&y,&s);
            y+=h;
            if (s==0){
               path[x].push_back(x+h+w),path[y].push_back(y+h+w);
               rpath[x+h+w].push_back(x),rpath[y+h+w].push_back(y);
            }
            else if (s==1){
               path[x+h+w].push_back(x),path[y+h+w].push_back(y);
               rpath[x].push_back(x+h+w),rpath[y].push_back(y+h+w);
            }
            else if (s==2){
               path[x].push_back(y+h+w),path[y].push_back(x+h+w);
               rpath[y+h+w].push_back(x),rpath[x+h+w].push_back(y);
            }
            else{
               path[x+h+w].push_back(y),path[y+h+w].push_back(x);
               rpath[y].push_back(x+h+w),rpath[x].push_back(y+h+w);
            }
         }
         (ok())?puts("YES"):puts("NO");
      }
   return 0;
}
