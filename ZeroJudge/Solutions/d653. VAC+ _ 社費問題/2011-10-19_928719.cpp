#include <cstdio>
#include <cstring>
#include <algorithm>

int a[100],b[101],c[101],num,L[101],R[101],m,now[100];
void dfs(int x,int d,int cnt){
    if (x==m){
        for (int i=0;i<m;i++){
            if (i)
                printf(" ");
            printf("%d",now[i]);
        }
        puts("");
        return;
    }
    for (int i=d;i!=0;i=R[i]){
        if (cnt<m-x)
            break;
        now[x]=b[i];
        c[i]--;
        if (c[i]==0)
            L[R[i]]=L[i],R[L[i]]=R[i];
        dfs(x+1,((c[i]==0)?R[i]:i),cnt);
        if (c[i]==0)
            L[R[i]]=i,R[L[i]]=i;
        c[i]++;
        cnt-=c[i];
    }
}
int main()
{
    int n;
    while (scanf("%d %d",&n,&m)){
        if (n==0&&m==0)
            break;
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        std::stable_sort(a,a+n);
        int f=0,num=0;
        for (int i=0;i<n;i++){
            if (f!=a[i]){
                f=a[i];
                b[++num]=f;
                c[num]=0;
            }
            c[num]++;
        }
        for (int i=0;i<=num;i++)
            L[i]=i-1,R[i]=i+1;
        L[0]=num,R[num]=0;
        dfs(0,1,n);
    }
    return 0;
}
