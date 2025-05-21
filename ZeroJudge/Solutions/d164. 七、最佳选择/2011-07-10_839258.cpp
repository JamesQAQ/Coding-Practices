#include <cstdio>

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
int main()
{
    int n,m,a[15000],ans,sum;
    while (scanf("%d %d",&n,&m)==2){
        sum=0;
        for (int i=0;i<n;i++)
            a[i]=input();
        for (int i=0;i<m;i++){
            sum+=a[i];
            a[i+n]=a[i];
        }
        ans=sum;
        for (int i=m;i<n+m;i++){
            sum+=a[i]-a[i-m];
            if (sum>ans)
                ans=sum;
        }
        printf("%d\n",ans);
    }
    return 0;
}
