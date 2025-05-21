#include <cstdio>

int a[500],b[500],num,n;
void LIS(){
    num=0;
    for (int i=0;i<n;i++){
        if (num==0||a[i]>=b[num-1])
            b[num++]=a[i];
        else{
            int l=0,r=num,mid;
            while (l<=r){
                mid=(l+r)/2;
                if (a[i]>=b[mid])
                    l=mid+1;
                else
                    r=mid-1;
            }
            b[l]=a[i];
        }
    }
}
int main()
{
    while (scanf("%d",&n)==1){
        for (int i=n-1;i>=0;i--)
            scanf("%d",&a[i]);
        LIS();
        printf("%d\n",num);
    }
    return 0;
}
