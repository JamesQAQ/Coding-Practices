#include <cstdio>
#include <algorithm>

int x[100001],y[100001],t[100000];
bool cmp(int i,int j){
    if (x[i]!=x[j])
        return x[i]<x[j];
    return y[i]<y[j];
}
bool visit[200001],mark[200001];
struct Node {int no,to;} path[100001][4];
int stack[100001],f[100001];
bool instack[100001]={};
void work(int X){
    //printf("work %d\n",X);
    int top=1;
    stack[0]=X;
    f[0]=0;
    instack[X]=true;
    while (top){
        int x=stack[top-1],d=(f[top-1]+2)%4;
        //printf("top %d x %d\n",top,x);
        //getchar();
        bool foundedge=false;
        int cnt[4]={};
        for (int i=(d+1)%4;cnt[i]==0;i=(i+1)%4){
            cnt[i]++;
            int to=path[x][i].to;
            if (to==-1)
                continue;
            int no=path[x][i].no;
            if (!visit[no]){
                if (instack[to]){
                    if (top>=2&&stack[top-2]==to){
                        mark[no]=true;
                        //printf("ans %d\n",no);
                        visit[no]=true;
                        instack[stack[top-1]]=false;
                        top--;
                    }
                    else{
                        visit[no]=true;
                        while (stack[top-1]!=to){
                            visit[path[stack[top-2]][f[top-1]].no]=true;
                            instack[stack[top-1]]=false;
                            top--;
                        }
                    }
                }
                else{
                    f[top]=i;
                    instack[to]=true;
                    stack[top++]=to;
                }
                foundedge=true;
                break;
            }
        }
        if (foundedge)
            continue;
        //puts("no edge");
        instack[stack[top-1]]=false;
        top--;
    }
}
void swap(int &a,int &b){
    a^=b^=a^=b;
}
int main()
{
    int n,m,a,b;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d %d",&x[i],&y[i]),t[i-1]=i;
        for (int j=0;j<4;j++)
            path[i][j].to=-1;
    }
    std::stable_sort(t,t+n,cmp);
    scanf("%d",&m);
    for (int i=1;i<=m;i++){
        visit[i]=mark[i]=false;
        scanf("%d %d",&a,&b);
        if (x[a]==x[b]){
            if (y[a]>y[b])
                swap(a,b);
            path[a][0].no=path[b][2].no=i;
            path[a][0].to=b;
            path[b][2].to=a;
        }
        else if (y[a]==y[b]){
            if (x[a]>x[b])
                swap(a,b);
            path[a][1].no=path[b][3].no=i;
            path[a][1].to=b;
            path[b][3].to=a;
        }
    }
    for (int i=0;i<n;i++)
        work(t[i]);
    int ans=0;
    for (int i=1;i<=m;i++)
        if (mark[i])
            ans++;
    printf("%d\n",ans);
    for (int i=1;i<=m;i++)
        if (mark[i])
            printf("%d\n",i);
}
