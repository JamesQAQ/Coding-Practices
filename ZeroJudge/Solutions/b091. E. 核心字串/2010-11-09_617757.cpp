#include <iostream>
using namespace std;

int main()
{
    int n,from,end,ansi,ansj,num[26],fnum;
    char s[1000000];
    while (scanf("%d",&n))
    {
        if (n==0)
            break;
        scanf("%s",&s);
        if (n<26)
            puts("not found");
        else
        {
            memset(num,0,sizeof(num));
            fnum=0;
            ansi=0;
            ansj=0;
            for (from=0,end=0;end<n;end++)
            {
                num[s[end]-'a']++;
                if (num[s[end]-'a']==1)
                    fnum++;
                while (num[s[from]-'a']>1)
                    num[s[from++]-'a']--;
                if (fnum==26)
                    if (ansj==0||end-from<ansj-ansi)
                    {
                        ansi=from;
                        ansj=end;
                        if (ansj-ansi==25)
                            break;
                    }
            }
            if (ansj==0)
                puts("not found");
            else
            {
                for (int i=ansi;i<=ansj;i++)
                    printf("%c",s[i]);
                puts("");
            }
        }
    }
    return 0;
}
