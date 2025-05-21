#include <cstdio>
#include <algorithm>

int dice[1000000][6],t[1000000];
int m[24][3]={{2,0,1}
             ,{2,1,3}
             ,{2,3,4}
             ,{2,4,0}
             ,{0,5,1}
             ,{0,1,2}
             ,{0,2,4}
             ,{0,4,5}
             ,{5,3,1}
             ,{5,1,0}
             ,{5,0,4}
             ,{5,4,3}
             ,{3,2,1}
             ,{3,1,5}
             ,{3,5,4}
             ,{3,4,2}
             ,{1,0,5}
             ,{1,5,3}
             ,{1,3,2}
             ,{1,2,0}
             ,{4,3,5}
             ,{4,5,0}
             ,{4,0,2}
             ,{4,2,3}};
void spin(int a[],int b[],int c[]){
    for (int i=0;i<3;i++)
        b[i]=a[c[i]],b[i+3]=a[(c[i]+3)%6];
}
bool better(int a[],int b[]){
    for (int i=0;i<6;i++){
        if (b[i]>a[i])
            return false;
        if (a[i]>b[i])
            return true;
    }
    return false;
}
void work(int a[]){
    int b[6],best[6];
    spin(a,best,m[0]);
    for (int i=1;i<24;i++){
        spin(a,b,m[i]);
        if (better(best,b)){
            for (int j=0;j<6;j++)
                best[j]=b[j];
        }
    }
    for (int i=0;i<6;i++)
        a[i]=best[i];
}
bool cmp(int i,int j){
    for (int k=0;k<6;k++){
        if (dice[i][k]<dice[j][k])
            return false;
        if (dice[i][k]>dice[j][k])
            return true;
    }
    return false;
}
bool same(int a[],int b[]){
    for (int i=0;i<6;i++)
        if (a[i]!=b[i])
            return false;
    return true;
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        for (int j=0;j<6;j++)
            scanf("%d",&dice[i][j]);
        work(dice[i]);
        t[i]=i;
    }
    std::stable_sort(t,t+n,cmp);
    int f[6]={},cnt=0;
    for (int i=0;i<n;i++)
        if (!same(f,dice[t[i]])){
            for (int j=0;j<6;j++)
                f[j]=dice[t[i]][j];
            cnt++;
        }
    printf("%d\n",cnt);
}
