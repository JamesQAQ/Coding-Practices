#include <cstdio>
#include <cstring>

char Month[2][10]={"January","February"};
int cnt(int y){
    return y/400-y/100+y/4;
}
int main()
{
    int cases,date,year,tmp;
    char s[10];
    scanf("%d",&cases);
    for (int t=1;t<=cases;t++){
        scanf("%s %d, %d",s,&date,&year);
        if (strcmp(s,Month[0])==0||strcmp(s,Month[1])==0)
            year--;
        tmp=cnt(year);
        scanf("%s %d, %d",s,&date,&year);
        if (strcmp(s,Month[0])==0||(strcmp(s,Month[1])==0&&date!=29))
            year--;
        //printf("%d %d y %d\n",tmp,cnt(year),year);
        printf("Case %d: %d\n",t,cnt(year)-tmp);
    }
}
