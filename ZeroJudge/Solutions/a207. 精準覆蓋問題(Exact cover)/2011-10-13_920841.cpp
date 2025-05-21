#include <cstdio>

int L[150000],R[150000],U[150000],D[150000],C[150000],S[150000],ans;
void insert(int x,int c){
    U[x]=U[c],D[x]=c;
    D[U[c]]=x,U[c]=x;
    C[x]=c,S[c]++;
}
void remove(int c){
    L[R[c]]=L[c];
    R[L[c]]=R[c];
    for (int i=D[c];i!=c;i=D[i])
        for (int j=R[i];j!=i;j=R[j]){
            U[D[j]]=U[j];
            D[U[j]]=D[j];
            S[C[j]]--;
        }
}
void resume(int c){
    for (int i=D[c];i!=c;i=D[i])
        for (int j=R[i];j!=i;j=R[j]){
            U[D[j]]=j;
            D[U[j]]=j;
            S[C[j]]++;
        }  
    L[R[c]]=c;
    R[L[c]]=c;  
}
void dfs(int x){
    if (x>=ans)
        return;
    if (R[0]==0){
        ans=x;
        return;
    }
    int mini=2147483647,c;
    for (int i=R[0];i!=0;i=R[i])
        if (S[i]<mini){
            mini=S[i];
            c=i;
        }
    remove(c);
    for (int i=D[c];i!=c;i=D[i]){
        for (int j=R[i];j!=i;j=R[j])
            remove(C[j]);
        dfs(x+1);
        for (int j=R[i];j!=i;j=R[j])
            resume(C[j]);
    }
    resume(c);
}
int main()
{
    int n,m,num=0,temp,c;
    while (scanf("%d %d",&n,&m)==2){
        for (int i=0;i<=m;i++){
            U[i]=D[i]=i;
            L[i]=i-1,R[i]=i+1;
            S[i]=0;
        }
        L[0]=m,R[m]=0;
        num=m+1;
        for (int i=0;i<n;i++){
            scanf("%d",&temp);
            for (int i=0;i<temp;i++){
                scanf("%d",&c);
                if (i==0)
                    L[num]=num+temp-1;
                else
                    L[num]=num-1;
                if (i==temp-1)
                    R[num]=num-temp+1;
                else
                    R[num]=num+1;
                insert(num,c);
                num++;
            }
        }
        ans=2147483647;
        dfs(0);
        if (ans==2147483647)
            puts("No");
        else
            printf("%d\n",ans);
    }
    return 0;
}
