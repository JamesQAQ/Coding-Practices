#include <cstdio>

char s[100000][11];
int a[100000],b[100000];
bool cmp(int i,int j){
    int k=0;
    for (;s[i][k]&&s[j][k];k++){
        if (s[i][k]<s[j][k]) return true;
        if (s[i][k]>s[j][k]) return false;
    }
    return s[j][k];
}
void merge(int l,int mid,int r){
    for (int i=l;i<=r;i++)
        b[i]=a[i];
    int atl=l,atr=mid+1;
    for (int i=l;i<=r;i++){
        if (atl==mid+1||(atr<=r&&cmp(b[atr],b[atl])))
            a[i]=b[atr++];
        else
            a[i]=b[atl++];
    }    
}
void merge_sort(int l,int r){
    if (l==r)
        return;
    int mid=(l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    merge(l,mid,r);
}
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for (int i=0;i<n;i++)
        gets(s[i]),a[i]=i;
    merge_sort(0,n-1);
    for (int i=0;i<n;i++)
        puts(s[a[i]]);
}
