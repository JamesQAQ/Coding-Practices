#include <cstdio>
#include <algorithm>

int cases,v[10],t[10];
char s[10][101];
bool cmp(int i,int j){
    return v[i]>v[j];
}
int main()
{
    while (scanf("%d",&cases)==1)
        for (int j=1;j<=cases;j++){
            for (int i=0;i<10;i++){
                scanf("%s %d",s[i],&v[i]);
                t[i]=i;
            }
            std::sort(t,t+10,cmp);
            printf("Case #%d:\n%s\n",j,s[t[0]]);
            for (int i=1;i<10;i++){
                if (v[t[i]]!=v[t[i-1]])
                    break;
                printf("%s\n",s[t[i]]);
            }
        }
    return 0;
}
