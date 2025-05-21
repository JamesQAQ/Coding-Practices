#include <cstdio>

int abs(int x){
    return (x<0)?-x:x;
}
bool work(int n,int a[],bool use[]){
    for (int i=0;i<n-1;i++){
        int tmp=abs(a[i+1]-a[i]);
        if (tmp>=n||use[tmp])
            return false;
        use[tmp]=true;
    }
    return true;
}
int main()
{
    bool use[3000];
    int n,a[3000];
    while (scanf("%d",&n)==1){
        for (int i=0;i<n;i++)
            use[i]=false,scanf("%d",&a[i]);
        puts((work(n,a,use))?"Jolly":"Not jolly");
    }
}
