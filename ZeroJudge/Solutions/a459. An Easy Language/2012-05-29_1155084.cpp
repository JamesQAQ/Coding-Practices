#include <cstdio>

char s[1000000],tmp[10000];
int to[1000000];
int get(int at){
    int sum=0;
    while (s[at]=='!')
        at++,sum++;
    return sum;
}
int findI(int at){
    int l=1,r=0;
    while (1){
        if (s[at]=='C'){
            l++;
            at+=12;
        }
        else if (s[at]=='I'){
            r++;
            if (l==r)
                break;
            at+=14;
        }
        else
            at++;
    }
    return at;
}
int main()
{
    bool head[128]={};
    head['(']=head['L']=head['C']=head['I']=true;
    int len=0,Brain[240]={},Ptr=0;
    while (gets(tmp)!=NULL){
        for (int i=0;tmp[i];i++)
            s[len++]=tmp[i];
    }
    int at=0;
    while (1){
        while (at<len&&!head[s[at]])
            at++;
        if (at==len)
            break;
        if (s[at]=='('){
            int p=get(at+9);
            if (p==0) Ptr++;
            else if (p==1) Brain[Ptr]++;
            else if (p==2) Ptr--;
            else Brain[Ptr]--;
            at+=20+p*2;
        }
        else if (s[at]=='L')
            putchar(Brain[Ptr]),at+=16;
        else if (s[at]=='C'){
            if (to[at]==0){
                to[at]=findI(at+12);
                to[to[at]]=at;
            }
            if (Brain[Ptr])
                at+=12;
            else
                at=to[at]+14;
        }
        else
            at=to[at]-6;
    }
}
