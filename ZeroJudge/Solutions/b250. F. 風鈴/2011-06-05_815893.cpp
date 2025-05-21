#include <cstdio>
#include <string.h>

int count(char s[],int l,int r){
    int sum=0,x=0;
    for (int i=l;i<=r;i++){
        if (s[i]<='9'&&s[i]>='0')
            x=x*10+s[i]-48;
        else{
            sum+=x;
            x=0;
        }
    }
    sum+=x;
    return sum;
}
bool ok(char s[],int l,int r){
    int a=0,b=0,i=l+1;
    for (;i<r;i++){
        if (a==b&&s[i]==',')
            break;
        if (s[i]=='(')
            a++;
        else if (s[i]==')')
            b++;
    }
    if (a!=0&&!ok(s,l+1,i-1))
        return false;
    a=b=0;
    int j=i+1;
    for (;j<r;j++){
        if (s[j]=='(')
            a++;
        else if (s[j]==')')
            b++;
    }
    if (a!=0&&!ok(s,i+1,r-1))
        return false;
    if (count(s,l+1,i-1)!=count(s,i+1,r-1))
        return false;
    return true;
}
int main()
{
    int cases;
    char s[101];
    scanf("%d",&cases);
    while (cases--){
        scanf("%s",s);
        int len=strlen(s);
        (ok(s,0,len-1))?puts("Yes"):puts("No");
    }
    return 0;
}
