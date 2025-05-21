#include <cstdio>

int dp[2][59049],*pre,*now,*tmp,n,m,k,black[150],pow3[11]={1},pow2[11]={1};
bool map[150][10];
int tc[3],se[10];
int build(int loca,int x){
    for (int i=0;i<3;i++)
        tc[i]=0;
    for (int i=0;i<m;i++)
        se[i]=0;
    int cnt=0;
    while (x){
        se[cnt++]=x%3;
        x/=3;
    }
    tc[2]=black[loca+2];
    tc[0]=tc[1]=0;
    for (int i=m-1;i>=0;i--){
        tc[0]<<=1;
        tc[1]<<=1;
        if (se[i]>=1)
            tc[0]++;
        if (se[i]==2)
            tc[1]++;
    }
    tc[0]|=black[loca];
    tc[1]|=black[loca+1];
    int s=0;
    for (int i=0;i<m;i++)
        if (se[i]==2)
            s+=pow3[i];
    return s;
}
bool ok2(int x){
    int s=pow2[x]+pow2[x+1]+pow2[x+2];
    //printf("ok2 %d s %d\n",x,s);
    return (tc[0]&s)==0&&(tc[1]&s)==0;
}
bool ok3(int x){
    int s=pow2[x]+pow2[x+1];
    //printf("tc & s %d %d %d\n",tc[0]&s,tc[1]&s,tc[2]&s);
    return (tc[0]&s)==0&&(tc[1]&s)==0&&(tc[2]&s)==0;
}
void dfs(int x,int s,int v){
    //printf("dfs %d %d %d\n",x,s,v);
    if (x>=m){
        if (now[s]==-1||v>now[s])
            now[s]=v;
        return;
    }
    dfs(x+1,s,v);
    if (x<m-2&&ok2(x)){
        //printf("x2 %d\n",x);
        dfs(x+3,s+pow3[x]+pow3[x+1]+pow3[x+2],v+1);
    }
    if (x<m-1&&ok3(x)){
        //printf("x3 %d\n",x);
        dfs(x+2,s+2*pow3[x]+2*pow3[x+1],v+1);
    }
}
int main()
{
    int a,b,full,cases;
    scanf("%d",&cases);
    pre=dp[0],now=dp[1];
    for (int i=1;i<=10;i++)
        pow3[i]=pow3[i-1]*3,pow2[i]=pow2[i-1]<<1;
    while (cases--){
        scanf("%d %d %d",&n,&m,&k);
        full=pow3[m];
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                map[i][j]=false;
        while (k--)
            scanf("%d %d",&a,&b),map[a-1][b-1]=true;
        for (int i=0;i<n;i++){
            black[i]=0;
            for (int j=m-1;j>=0;j--)
                black[i]=(black[i]<<1)+map[i][j];
            //printf("black %d\n",black[i]);
        }
        now[0]=0;
        for (int i=1;i<full;i++)
            now[i]=-1;
        for (int i=0;i<n;i++){
            //printf("iiiiiiiii %d\n",i);
            tmp=now,now=pre,pre=tmp;
            for (int j=0;j<full;j++)
                now[j]=-1;
            for (int j=0;j<full;j++)
                if (pre[j]!=-1){
                    //printf("pre[%d]=%d\n",j,pre[j]);
                    int s=build(i,j);
                    //for (int i=0;i<m;i++)
                    //    printf("%d",se[i]);
                    //puts("");
                    //printf("tc %d %d %d\n",tc[0],tc[1],tc[2]);
                    dfs(0,s,pre[j]);
                }
            //getchar();
        }
        printf("%d\n",now[0]);
    }
}
