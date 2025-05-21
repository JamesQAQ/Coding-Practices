#include <cstdio>
#include <cstring>

char s[1001];
int cnt=0;
struct Bignumber{
    char a[1000],num,l;
    void input(){
        scanf("%s",s);
        num=strlen(s);
        l=0;
        for (int i=0;i<num;i++)
            a[i]=s[num-i-1]-'0';
    }
    bool operator >(Bignumber b){
        if (num>b.num) return true;
        if (num<b.num) return false;
        for (int i=num-1;i>=0;i--){
            if (a[l+i]>b.a[b.l+i]) return true;
            if (a[l+i]<b.a[b.l+i]) return false;
        }
        return false;
    }
    void operator -=(Bignumber b){
        for (int i=0;i<b.num;i++)
            a[l+i]-=b.a[b.l+i];
        for (int i=0;i<num;i++)
            if (a[l+i]<0){
                a[l+i]+=2;
                a[l+i+1]--;
            }
        while (num&&a[l+num-1]==0)
            num--;
    }
    void check_zero(){
        while (num&&a[l]==0)
            l++,num--;
    }
    void print(){
        for (int i=l+num-1;i>=l;i--)
            printf("%d",a[i]);
    }
} *n,*m,*tmp,number[2];
void swap(){
    tmp=n,n=m,m=tmp;
}
int main()
{
    n=&number[0],m=&number[1];
    int cnt=0;
    n->input(),m->input();
    while (n->a[n->l]==0&&m->a[m->l]==0)
        n->l++,m->l++,cnt++;
    while (n->num!=0){
        if ((*m)>(*n)) swap();
        (*n)-=(*m);
        n->check_zero();
    }
    m->print();
    for (int i=0;i<cnt;i++)
        putchar('0');
    puts("");
}
