#include <cstdio>

int cnt[70000],num;
void build(){
    cnt[0]=0,cnt[1]=1,cnt[2]=2;
    int s=3;
    for (num=3;cnt[num-1]+s<=2000100000;num++,s+=2)
        cnt[num]=cnt[num-1]+s;
}
int search(int l,int r,int v){
    int mid;
    while (l<=r){
        mid=(l+r)/2;
        if (cnt[mid]>v)
            r=mid-1;
        else if (cnt[mid]<v)
            l=mid+1;
        else{
            r=mid;
            break;
        }
    }
    return r;
}
void work(int n){
    int at=search(1,num,n);
    if (at&1){
        int d=n-cnt[at],half=(cnt[at+1]-cnt[at])/2;
        if (d>half)
            printf("%d %d\n",at-(d-half),at);
        else
            printf("%d %d\n",at,1+d);
    }
    else{
        int d=n-cnt[at],half=(cnt[at+1]-cnt[at])/2;
        if (d>half)
            printf("%d %d\n",at,at-(d-half));
        else
            printf("%d %d\n",1+d,at);
    }
}
int main()
{
    build();
    int n;
    while (scanf("%d",&n),n)
        work(n);
}
