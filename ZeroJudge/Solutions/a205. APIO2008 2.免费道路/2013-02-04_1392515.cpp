#include <cstdio>

void Init(int &n,int &m,int &k,int U[],int V[],int C[]){
    scanf("%d %d %d",&n,&m,&k);
    for (int i=0;i<m;i++)
        scanf("%d %d %d",&U[i],&V[i],&C[i]);
}
void NoSolution(){
    puts("no solution");
}
void Solution(int u,int v,int c){
    printf("%d %d %d\n",u,v,c);
}
int u[100000],v[100000],c[100000],boss[20001],need[20000],num=0,ans[100000],ansnum=0;
bool use[100000]={};
int find(int x){
    return (x==boss[x])?x:boss[x]=find(boss[x]);
}
int main()
{
    int n,m,k;
    Init(n,m,k,u,v,c);
    for (int i=1;i<=n;i++)
        boss[i]=i;
    for (int i=0;i<m;i++)
        if (c[i])
            boss[find(v[i])]=find(u[i]);
    for (int i=0;i<m;i++)
        if (c[i]==0){
            if (find(u[i])!=find(v[i])){
                boss[find(v[i])]=find(u[i]);
                need[num++]=i;
                use[i]=true;
            }
        }
    if (num>k)
        NoSolution();
    else{
        for (int i=1;i<=n;i++)
            boss[i]=i;
        for (int i=0;i<num;i++){
            boss[find(v[need[i]])]=find(u[need[i]]);
            ans[ansnum++]=need[i];
        }
        for (int i=0;i<m;i++){
            if (ansnum==k)
                break;
            if (!use[i]&&c[i]==0){
                if (find(u[i])!=find(v[i])){
                    boss[find(v[i])]=find(u[i]);
                    ans[ansnum++]=i;
                }
            }
        }
        if (ansnum!=k)
            NoSolution();
        else{
            for (int i=0;i<m;i++)
                if (c[i])
                    if (find(u[i])!=find(v[i])){
                        boss[find(v[i])]=find(u[i]);
                        ans[ansnum++]=i;
                    }
            if (ansnum!=n-1)
                NoSolution();
            else{
                puts("yes");
            }
        }
    }
    //while (1);
}
