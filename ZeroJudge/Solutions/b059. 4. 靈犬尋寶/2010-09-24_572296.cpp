#include<stdio.h>
#include<stdlib.h>
main()
{
 int n;
 while(scanf("%d",&n)==1)
  {
   int map[106][106]={0},x,y;
   int a,b,c,d,startx,starty; 
     for(a=0;a<=105;a++) /*建出牆壁-1 怕靈犬走出方格造成RE*/ 
      {
       map[0][a]=-1;map[a][0]=-1;
       map[1][a]=-1;map[a][1]=-1;
       map[2][a]=-1;map[a][2]=-1;
       map[103][a]=-1;map[a][103]=-1;
       map[104][a]=-1;map[a][104]=-1;
       map[105][a]=-1;map[a][105]=-1;
      } 
    int ans=0; 
    for(a=0;a<n;a++) { scanf("%d %d",&x,&y);map[x+3][y+3]=-1; }
    scanf("%d %d",&startx,&starty);
    scanf("%d %d",&x,&y); map[x+3][y+3]=-2;
    int queue[10001][2]={0},top=0;
    queue[0][0]=startx+3;queue[0][1]=starty+3; 
    for(a=0;a<=top;a++) /*BFS*/ 
      {
       int nn=queue[a][0],mm=queue[a][1]; 
        if(map[nn+1][mm+3]==-2&&map[nn][mm+1]>=0) {ans+=map[nn][mm]+1;break;}
        if(map[nn-1][mm+3]==-2&&map[nn][mm+1]>=0) {ans+=map[nn][mm]+1;break;}
        if(map[nn-3][mm+1]==-2&&map[nn-1][mm]>=0) {ans+=map[nn][mm]+1;break;}
        if(map[nn-3][mm-1]==-2&&map[nn-1][mm]>=0) {ans+=map[nn][mm]+1;break;}
        if(map[nn-1][mm-3]==-2&&map[nn][mm-1]>=0) {ans+=map[nn][mm]+1;break;}
        if(map[nn+1][mm-3]==-2&&map[nn][mm-1]>=0) {ans+=map[nn][mm]+1;break;}
        if(map[nn+3][mm+1]==-2&&map[nn+1][mm]>=0) {ans+=map[nn][mm]+1;break;}
        if(map[nn+3][mm-1]==-2&&map[nn+1][mm]>=0) {ans+=map[nn][mm]+1;break;}  

        if(map[nn+1][mm+3]==0&&map[nn][mm+1]>=0) {map[nn+1][mm+3]+=map[nn][mm]+1;top++;queue[top][0]=nn+1;queue[top][1]=mm+3;}
        if(map[nn-1][mm+3]==0&&map[nn][mm+1]>=0) {map[nn-1][mm+3]+=map[nn][mm]+1;top++;queue[top][0]=nn-1;queue[top][1]=mm+3;}
        if(map[nn-3][mm+1]==0&&map[nn-1][mm]>=0) {map[nn-3][mm+1]+=map[nn][mm]+1;top++;queue[top][0]=nn-3;queue[top][1]=mm+1;}
        if(map[nn-3][mm-1]==0&&map[nn-1][mm]>=0) {map[nn-3][mm-1]+=map[nn][mm]+1;top++;queue[top][0]=nn-3;queue[top][1]=mm-1;}
        if(map[nn-1][mm-3]==0&&map[nn][mm-1]>=0) {map[nn-1][mm-3]+=map[nn][mm]+1;top++;queue[top][0]=nn-1;queue[top][1]=mm-3;}
        if(map[nn+1][mm-3]==0&&map[nn][mm-1]>=0) {map[nn+1][mm-3]+=map[nn][mm]+1;top++;queue[top][0]=nn+1;queue[top][1]=mm-3;}
        if(map[nn+3][mm+1]==0&&map[nn+1][mm]>=0) {map[nn+3][mm+1]+=map[nn][mm]+1;top++;queue[top][0]=nn+3;queue[top][1]=mm+1;}
        if(map[nn+3][mm-1]==0&&map[nn+1][mm]>=0) {map[nn+3][mm-1]+=map[nn][mm]+1;top++;queue[top][0]=nn+3;queue[top][1]=mm-1;} 
      }      
    if(ans==0) printf("impossible\n") ;
    else printf("%d\n",ans); 
  } 
 return 0;
}
