#include <cstdio>

int cnt(int x){
    int sum=0;
    while (x!=0)
        sum+=x%10,x/=10;
    return sum;
}
int Cnt(int x,int y,int z){
    int a=cnt(x)+cnt(y)+cnt(z);
    while (a>=10)
        a=cnt(a);
    return a;
}
int Abs(int x){
    return (x<0)?-x:x;
}
int main()
{
    int n,o,x,y,z,dis,ans;
    while (scanf("%d %d %d",&x,&y,&z)==3){
        o=Cnt(x,y,z);
        scanf("%d",&n);
        dis=2147483647;
        for (int i=0;i<n;i++){
            scanf("%d %d %d",&x,&y,&z);
            int d=Cnt(x,y,z);
            if (Abs(d-o)<dis)
                dis=Abs(d-o),ans=i+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
