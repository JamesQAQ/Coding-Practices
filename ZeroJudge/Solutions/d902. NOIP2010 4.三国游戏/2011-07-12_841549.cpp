#include <cstdio>
#include <algorithm>

bool cmp(int i,int j){
    return i>j;
}
int main()
{
    int n,a[500][500];
    while (scanf("%d",&n)==1){
        for (int i=0;i<n-1;i++){
            for (int j=i+1;j<n;j++){
                scanf("%d",&a[i][j]);
                a[j][i]=a[i][j];
            }
            a[i][i]=0;
        }
        for (int i=0;i<n;i++)
            std::stable_sort(a[i],a[i]+n,cmp);
        int ans=0;
        for (int i=0;i<n;i++)
            if (a[i][1]>ans)
                ans=a[i][1];
        printf("1\n%d\n",ans);
    }
    return 0;
}
