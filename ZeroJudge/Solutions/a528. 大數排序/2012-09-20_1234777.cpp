#include <cstdio>
#include <cstring>
#include <algorithm>

char s[1000][150];
int t[1000],len[1000];
bool cmp(int i,int j){
    char a=s[i][0],b=s[j][0];
    if (a=='-'&&b!='-')
        return true;
    if (a!='-'&&b=='-')
        return false;
    if (a=='-'&&b=='-'){
        if (len[i]!=len[j])
            return len[i]>len[j];
        for (int k=1;s[i][k]&&s[j][k];k++){
            if (s[i][k]>s[j][k]) return true;
            if (s[i][k]<s[j][k]) return false;
        }
    }
    if (a!='-'&&b!='-'){
        if (len[i]!=len[j])
            return len[i]<len[j];
        for (int k=0;s[i][k]&&s[j][k];k++){
            if (s[i][k]<s[j][k]) return true;
            if (s[i][k]>s[j][k]) return false;
        }
    }
}
int main()
{
    int n;
    while (scanf("%d",&n)==1){
        for (int i=0;i<n;i++)
            scanf("%s",s[i]),t[i]=i,len[i]=strlen(s[i]);
        std::stable_sort(t,t+n,cmp);
        for (int i=0;i<n;i++)
            puts(s[t[i]]);
    }
}
