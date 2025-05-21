#include <cstdio>

int main()
{
    int cnt[128];
    char S[4][20]={"adgjmptw ","behknqux","cfilorvy","sz"};
    for (int i=0;i<4;i++){
        for (int j=0;S[i][j];j++)
            cnt[S[i][j]]=i+1;
    }
    int cases;
    char s[10000];
    scanf("%d",&cases);
    getchar();
    for (int t=1;t<=cases;t++){
        gets(s);
        int sum=0;
        for (int i=0;s[i];i++)
            sum+=cnt[s[i]];
        printf("Case #%d: %d\n",t,sum);
    }
}

/*
---------------------
|      | abc | def  |
---------------------
| ghi  | jkl | mno  |
---------------------
| pqrs | tuv | wxyz |
---------------------
|      | <SP>|      |
---------------------
*/
