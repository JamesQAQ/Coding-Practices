#include <cstdio>

char s[10000000];
int num;
void plus(int x){
    if (x>=10){
        s[num++]=x/10+48;
        s[num++]=x%10+48;
    }
    else
        s[num++]=x+48;
}
int main()
{
    int n,a[100];
    while (scanf("%d",&n)==1){
        num=0;
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int l=0,r=n-1;
        while (1){
            if (r<l)
                break;
            plus(a[l]);
            for (int i=l+1;i<=r;i++){
                s[num++]=' ';
                plus(a[i]);
            }
            s[num++]='\n';
            l++;
            if (l>r)
                break;
            plus(a[r]);
            for (int i=r-1;i>=l;i--){
                s[num++]=' ';
                plus(a[i]);
            }
            s[num++]='\n';
            r--;
        }
        s[num++]='\0';
        printf("%s\n",s);
    }
    return 0;
}
