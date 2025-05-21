#include <cstdio>

char sa[100],sb[100];
bool ans[26],guess[26];
int ansnum,guessnum,cnt;
void work(){
    scanf("%s %s",sa,sb);
    for (int i=0;i<26;i++)
        ans[i]=guess[i]=false;
    ansnum=0;
    for (int i=0;sa[i];i++)
        if (!ans[sa[i]-'a']){
            ans[sa[i]-'a']=true;
            ansnum++;
        }
    guessnum=cnt=0;
    for (int i=0;sb[i];i++)
        if (!guess[sb[i]-'a']){
            if (ans[sb[i]-'a'])
                guessnum++;
            else
                cnt++;
            guess[sb[i]-'a']=true;
            if (cnt==7){
                puts("You lose.");
                return;
            }
            if (ansnum==guessnum){
                puts("You win.");
                return;
            }
        }
    puts("You chickened out.");
}
int main()
{
    int n;
    while (scanf("%d",&n),n!=-1){
        printf("Round %d\n",n);
        work();
    }
}
