#include <cstdio>
#include <algorithm>

int w,h;
char s[30],ch[26];
bool map[26][26];

bool error(){
    for (int i=0;i<w;i++)
        for (int j=0;j<h;j++){
            if (map[j][i]){
                if (j>0&&map[j-1][i])
                    return true;
                std::swap(ch[j],ch[j+1]);
            }
        }
    return false;
}
int main()
{
    while (scanf("%d %d",&w,&h)==2){
        for (int i=0;i<h;i++){
            scanf("%s",s);
            for (int j=0;j<w;j++)
                map[i][j]=(s[j]=='P')?false:true;
        }
        for (int i=0;i<=h;i++)
            ch[i]=i+'A';
        if (error()){
            puts("ERROR");
            continue;
        }
        for (int i=0;i<=h;i++){
            if (i){
                s[0]=' ';
                for (int j=0;j<w;j++)
                    s[j+1]=(map[i-1][j])?'|':' ';
                s[w+1]='\0';
                printf("%s\n",s);
            }
            s[0]=i+'A';
            for (int j=1;j<=w;j++)
                s[j]='-';
            s[w+1]=ch[i],s[w+2]='\0';
            printf("%s\n",s);
        }
        puts(" ");
    }
    return 0;
}
