#include <cstdio>

int n,stack[1000001],num[1000001],top,temp;
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
    int cases;
    long long ans;
    cases=input();
    while (cases--){
        n=input();
        top=0;
        ans=0;
        for (int i=0;i<n;i++){
            temp=input();
            while (top&&temp>stack[top-1]){
                ans+=(long long)num[top-1];
                top--;
            }
            if (top>0&&stack[top-1]==temp){
                ans+=(long long)num[top-1];
                if (top-1>0)
                    ans++;
                num[top-1]++;
            }
            else{
                if (top>0)
                    ans++;
                stack[top]=temp,num[top]=1;
                top++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
