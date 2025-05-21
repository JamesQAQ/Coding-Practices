#include <cstdio>
#include <vector>

std::vector <int> pre[26];
int num[26],total,cnt;
char ans[20];
void input(char s[],int a[],int &b){
    b=0;
    for (int i=0;s[i];i++){
        b++;
        a[s[i]-'a']++;
    }
}
bool ok(int x){
    int p=pre[x].size();
    for (int i=0;i<p;i++)
        if (num[pre[x][i]])
            return false;
    return true;
}
void dfs(int x){
    if (cnt==10)
        return;
    if (x==total){
        puts(ans);
        cnt++;
        return;
    }
    for (int i=0;i<26;i++)
        if (num[i]&&ok(i)){
            ans[x]=i+'a';
            num[i]--;
            dfs(x+1);
            if (cnt==10)
                return;
            num[i]++;
        }
}
int main()
{
    int n,m,cases;
    char s[20];
    scanf("%d",&cases);
    while (cases--){
        for (int i=0;i<26;i++)
            pre[i].clear(),num[i]=0;
        scanf("%s",s);
        input(s,num,total);
        scanf("%d",&m);
        char a,b;
        while (m--){
            scanf(" %c %c",&a,&b);
            pre[b-'a'].push_back(a-'a');
        }
        cnt=0;
        ans[total]=0;
        dfs(0);
        if (cnt==0)
            puts("NANJ你唬我");
    }
}
