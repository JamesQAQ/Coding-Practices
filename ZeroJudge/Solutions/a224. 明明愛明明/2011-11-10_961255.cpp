#include <cstdio>
#include <cstring>
bool ok(int x[]){
    int s=0;
    for (int i=0;i<26;i++){
        if (x[i]&1)
            s++;
        if (s>1)
            return false;
    }
    return true;
}
int main()
{
    int cnt[26];
    char s[1000];
    while (scanf("%s",s)==1){
        int len=strlen(s);
        for (int i=0;i<26;i++)
            cnt[i]=0;
        for (int i=0;i<len;i++){
            if (s[i]<='Z'&&s[i]>='A')
                cnt[s[i]-'A']++;
            else if (s[i]<='z'&&s[i]>='a')
                cnt[s[i]-'a']++;
        }
        puts((ok(cnt))?"yes !":"no...");
    }
    return 0;
}
