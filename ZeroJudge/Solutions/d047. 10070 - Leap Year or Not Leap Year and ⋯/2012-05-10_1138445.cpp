#include <cstring>
#include <cstdio>

bool leap(char s[],int len){
    if (s[len-1]=='0'&&s[len-2]=='0'){
        int x=(s[len-4]-'0')*10+s[len-3]-'0';
        return (x%4==0);
    }
    int x=(s[len-2]-'0')*10+s[len-1]-'0';
    return (x%4==0);
}
bool mod15(char s[],int len){
    if (s[len-1]=='0'||s[len-1]=='5'){
        int sum=0;
        for (int i=0;i<len;i++)
            sum+=s[i]-'0';
        return (sum%3==0);
    }
    return false;
}
bool mod55(char s[],int len){
    if (s[len-1]=='0'||s[len-1]=='5'){
        int sum=0;
        for (int i=0;i<len;i++){
            if (i&1)
                sum+=s[i]-'0';
            else
                sum-=s[i]-'0';
        }
        return (sum%11==0);
    }
    return false;
}
int main()
{
    int len;
    char s[100000];
    while (scanf("%s",s)==1){
        len=strlen(s);
        bool non=true;
        if (leap(s,len))
            puts("This is leap year."),non=false;
        if (mod15(s,len))
            puts("This is huluculu festival year."),non=false;
        if (leap(s,len)&&mod55(s,len))
            puts("This is bulukulu festival year.");
        if (non)
            puts("This is an ordinary year.");
        puts("");
    }
}
