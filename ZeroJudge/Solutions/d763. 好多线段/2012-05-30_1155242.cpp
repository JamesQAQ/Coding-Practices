#include <cstdio>
#include <algorithm>

void getin(char s[],int a[],int &num){
    int x=num=0;
    for (int i=0;s[i];i++){
        if (s[i]==' '){
            if (x!=0)
                a[num++]=x;
            x=0;
        }
        else
            x=x*10+s[i]-48;
    }
    if (x!=0)
        a[num++]=x;
}
int cut=1000000000;
struct Node{
    int a[4],num;
    void operator +=(Node b){
        if (b.num>num){
            for (int i=num;i<b.num;i++)
                a[i]=0;
            num=b.num;
        }
        for (int i=0;i<b.num;i++)
            a[i]+=b.a[i];
        for (int i=0;i<num-1;i++)
            if (a[i]>=cut){
                a[i+1]++;
                a[i]-=cut;
            }
        if (a[num-1]>=cut){
            a[num-1]-=cut;
            a[num++]=1;
        }
    }
    void print(){
        printf("%d",a[num-1]);
        for (int i=num-2;i>=0;i--)
            printf("%09d",a[i]);
        puts("");
    }
} ans,dp[1000002];
int main()
{
    char s[10000];
    int a[100],num,maxx;
    while (gets(s)){
        getin(s,a,num);
        if (num==0)
            break;
        std::stable_sort(a,a+num);
        maxx=a[num-1];
        for (int i=1;i<=maxx+1;i++)
            dp[i].num=0;
        dp[0].a[0]=dp[0].num=1;
        ans.num=0;
        for (int i=0;i<num;i++){
            int v=a[i];
            ans+=dp[maxx+1];
            dp[maxx+1]+=dp[maxx+1];
            for (int j=maxx;j>=0;j--){
                if (j>v)
                    ans+=dp[j];
                if (j+v>maxx)
                    dp[maxx+1]+=dp[j];
                else
                    dp[j+v]+=dp[j];
            }
        }
        ans.print();
    }
}
