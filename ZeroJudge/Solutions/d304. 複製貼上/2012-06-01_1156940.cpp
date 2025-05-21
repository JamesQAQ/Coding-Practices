#include <cstdio>

int mini,num,n;
bool ans[6000][10000],now[10000];
void print(bool a[]){
    printf("Ctrl C");
    for (int i=0;i<mini;i++)
        printf(" + %c",(a[i])?'C':'V');
    puts("");
}
void dfs(int x,int sum,int copy){
    if (x>mini)
        return;
    if ((n-sum)%copy)
        return;
    if (sum==n){
        if (x<mini)
            mini=x,num=0;
        for (int i=0;i<mini;i++)
            ans[num][i]=now[i];
        num++;
        return;
    }
    if (x&&!now[x-1]){
        now[x]=true;
        dfs(x+1,sum,sum);
    }
    now[x]=false;
    dfs(x+1,sum+copy,copy);
}
int main()
{
    while (scanf("%d",&n)==1){
        mini=2147483647;
        dfs(0,1,1);
        printf("min : %d\nway : %d\n",mini+1,num);
        for (int i=0;i<num;i++)
            print(ans[i]);
    }
}
