#include <cstdio>
#include <algorithm>

int a[100000],t[100000];
bool cmp(int i,int j){
    return a[i]<a[j];
}
int input(){
    char c=getchar();
    while (c<'0'||c>'9')
        c=getchar();
    int x=c-48;
    c=getchar();
    while (c>='0'&&c<='9'){
        x=x*10+c-48;
        c=getchar();
    }
    return x;
}
int search(int l,int r,int v){
    int mid;
    while (l<=r){
        mid=(l+r)/2;
        if (v>a[t[mid]])
            l=mid+1;
        else if (v<a[t[mid]])
            r=mid-1;
        else
            return t[mid]+1;
    }
}
int main()
{
    int cases,n,k,L;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d",&n,&k);
        for (int i=0;i<n;i++)
            a[i]=input(),t[i]=i;
        std::stable_sort(t,t+n,cmp);
        for (int i=0;i<k;i++){
            L=input();
            printf("%d\n",search(0,n,L));
        }
    }
    return 0;
}
