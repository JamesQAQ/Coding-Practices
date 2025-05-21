#include <cstdio>

char s[20];
int at[9]={0,2,3,4,6,7,8,9,10},v[256];
bool ok(){
    int sum=0;
    for (int i=0;i<9;i++)
        sum+=v[s[at[i]]]*(i+1);
    if (sum%11==v[s[12]])
        return true;
    else{
        s[12]=(sum%11==10)?'X':sum%11+48;
        printf("%s\n",s);
        return false;
    }
}
int main()
{
    for (int i=0;i<10;i++)
        v[i+48]=i;
    v['X']=10;
    while (scanf("%s",s)!=EOF)
        if (ok())
            puts("Right");
    return 0;
}
