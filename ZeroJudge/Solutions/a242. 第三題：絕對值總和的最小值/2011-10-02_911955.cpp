#include <cstdio>
#include <algorithm>

struct Node {int a,x;} data[100000];
int input(){
    char c=getchar();
    while (c==' '||c=='\n')
        c=getchar();
    int x=c-48;
    c=getchar();
    while (c!=' '&&c!='\n'){
        x=x*10+c-48;
        c=getchar();
    }
    return x;
}
bool cmp(int i,int j){
    return data[i].x<data[j].x;
}
int Abs(int x){
    return (x<0)?-x:x;
}
int main()
{
    int cases,n,t[100000],all,s,v;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d",&n);
        all=s=0;
        for (int i=0;i<n;i++){
            data[i].a=input();
            data[i].x=input();
            t[i]=i;
            data[i].x/=data[i].a;
            all+=data[i].a;
        }
        std::stable_sort(t,t+n,cmp);
        for (int j=0;j<n;j++){
            int i=t[j];
            s+=data[i].a;
            if (2*s-all>=0){
                v=data[i].x;
                break;
            }
        }
        long long ans=0;
        for (int i=0;i<n;i++)
            ans+=data[i].a*Abs(data[i].x-v);
        printf("%lld\n",ans);
    }
    return 0;
}
