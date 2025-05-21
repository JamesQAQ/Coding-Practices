#include <cstdio>
#include <cstring>
#include <algorithm>

char s[100001],s2[100001];
int L,t[100000],len;
bool one;
bool cmp(int i,int j){
    for (int k=0;k<L;k++){
        if (s[i+k]<s[j+k]) return true;
        if (s[i+k]>s[j+k]) return false;
    }
    return true;
}
bool notsame(){
    for (int i=0;s[i];i++)
        if (s[i]!=s2[i])
            return true;
    return false;
}
void work(int i){
    int num=len/i;
    for (int j=0;j<num;j++)
        t[j]=j*i;
    L=i;
    std::stable_sort(t,t+num,cmp);
    int cnt=0;
    for (int j=0;j<num;j++){
        int at=t[j];
        for (int k=0;k<i;k++)
            s2[cnt++]=s[at+k];
    }
    s2[cnt]='\0';
    if (notsame()) puts(s2),one=true;
}
int stack[100],top;
int main()
{
    while (scanf("%s",s)==1){
        len=strlen(s);
        one=false;
        top=0;
        for (int i=1;i*i<=len;i++)
            if (len%i==0){
                work(i);
                if (i*i!=len)
                    stack[top++]=len/i;
            }
        while (top>1)
            work(stack[top-1]),top--;
        if (!one) puts("bomb!");
    }
}
