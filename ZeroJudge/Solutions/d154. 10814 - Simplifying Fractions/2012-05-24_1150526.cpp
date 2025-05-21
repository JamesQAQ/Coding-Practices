#include <cstdio>
#include <iostream>
#include <cstring>

bool cmp(int a[],int anum,int b[],int bnum,int shift){
    if (bnum+shift>anum)
        return false;
    if (bnum+shift<anum)
        return true;
    for (int i=bnum-1;i>=0;i--){
        if (a[i+shift]>b[i])
            return true;
        if (a[i+shift]<b[i])
            return false;
    }
    return true;
}
int tmp[100];
struct Node{
    int a[100],num;
    void check(){
        while (num&&a[num-1]==0)
            num--;
    }
    void print(){
        for (int i=num-1;i>=0;i--)
            printf("%d",a[i]);
    }
    void operator %=(Node b){
        if (cmp(a,num,b.a,b.num,0)){
            int d=num-b.num;
            for (int i=d;i>=0;i--){
                while (cmp(a,num,b.a,b.num,i)){
                    for (int j=0;j<b.num;j++)
                        a[j+i]-=b.a[j];
                    for (int j=0;j<num;j++)
                        if (a[j]<0){
                            a[j+1]--;
                            a[j]+=10;
                        }
                    check();
                }
            }
        }
    }
    void operator /=(Node b){
        if (cmp(a,num,b.a,b.num,0)){
            int d=num-b.num;
            for (int i=d;i>=0;i--){
                tmp[i]=0;
                while (cmp(a,num,b.a,b.num,i)){
                    for (int j=0;j<b.num;j++)
                        a[j+i]-=b.a[j];
                    for (int j=0;j<num;j++)
                        if (a[j]<0){
                            a[j+1]--;
                            a[j]+=10;
                        }
                    tmp[i]++;
                    check();
                }
            }
            num=d+1;
            for (int i=0;i<num;i++)
                a[i]=tmp[i];
            check();
        }
    }
    void get(char s[]){
        num=strlen(s);
        for (int i=0;i<num;i++)
            a[i]=s[num-i-1]-'0';
    }
} a,b,g;
void gcd(Node m,Node n){
    while (m.num&&n.num){
        m%=n;
        std::swap(m,n);
    }
    g=(m.num)?m:n;
}
int main()
{
    int cases;
    char sa[100],sb[100],c;
    scanf("%d",&cases);
    while (cases--){
        scanf("%s %c %s",sa,&c,sb);
        a.get(sa),b.get(sb);
        gcd(a,b);
        a/=g,b/=g;
        a.print();
        printf(" / ");
        b.print();
        puts("");
    }
}
