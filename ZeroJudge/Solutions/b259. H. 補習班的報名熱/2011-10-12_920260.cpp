#include <cstdio>
#include <algorithm>
#include <iostream>
int L[30000],R[30000],U[30000],D[30000],S[30000],C[30000],sum;
struct Node {int a,b;} now[500],ans[500];
void insert(int x,int c){
    D[U[c]]=x;
    U[x]=U[c];
    U[c]=x;
    D[x]=c;
    C[x]=c;
    S[c]++;
}
bool cmp(Node i,Node j){
    return i.a<j.a;
}
void remove(int x){
    L[R[x]]=L[x];
    R[L[x]]=R[x];
    for (int i=D[x];i!=x;i=D[i])
        for (int j=R[i];j!=i;j=R[j]){
            S[C[j]]--;
            U[D[j]]=U[j];
            D[U[j]]=D[j];
        }
}
void resume(int x){
    for (int i=U[x];i!=x;i=U[i])
        for (int j=L[i];j!=i;j=L[j]){
            S[C[j]]++;
            U[D[j]]=j;
            D[U[j]]=j;
        }
    L[R[x]]=x;
    R[L[x]]=x;
}
void dfs(int x){
    if (sum>1)
        return;
    if (R[0]==0){
        sum++;
        for (int i=0;i<x;i++)
            ans[i]=now[i];
        return;
    }
    int mini=2147483647,c;
    for (int i=R[0];i!=0;i=R[i])
        if (S[i]<mini){
            mini=S[i];
            c=i;
        }
    remove(c);
    now[x].a=c;
    for (int i=D[c];i!=c;i=D[i]){
        now[x].b=C[R[i]];
        for (int j=R[i];j!=i;j=R[j])
            remove(C[j]);
        dfs(x+1);
        if (sum>1)
            return;
        for (int j=L[i];j!=i;j=L[j])
            resume(C[j]);
    }
    resume(c);
}
int main()
{
    int n,m,cases,a,b,num;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d",&n,&m);
        num=n+1;
        for (int i=0;i<=n;i++){
            U[i]=D[i]=i;
            L[i]=i-1,R[i]=i+1;
            S[i]=0;
        }
        R[n]=0;
        L[0]=n;
        for (int i=0;i<m;i++){
            scanf("%d %d",&a,&b);
            insert(num,a);
            insert(num+1,b);
            L[num]=R[num]=num+1;
            L[num+1]=R[num+1]=num;
            num+=2;
        }
        sum=0;
        dfs(0);
        if (sum>1||sum==0)
            puts("NO");
        else{
            puts("YES");
            for (int i=0;i<n/2;i++)
                if (ans[i].a>ans[i].b)
                    std::swap(ans[i].a,ans[i].b);
            std::stable_sort(ans,ans+n/2,cmp);
            for (int i=0;i<n/2;i++)
                printf("%d %d\n",ans[i].a,ans[i].b);
        }
    }
    return 0;
}
