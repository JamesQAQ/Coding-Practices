#include <stdio.h>

int v[1000002],num;
int judge(int x){
    while (x>3)
        x>>=1;
    return x;
}
int minsame(int x){
    if (x==2)
        return 2;
    int p=x,s=1;
    while (x>2)
        x>>=1,s<<=1;
    return (p+s>num)?(p+s)>>1:p+s;
}
int maxsame(int x){
    int p=x,s=1;
    while (x>3)
        x>>=1,s<<=1;
    return p-s;
}
void minup(int x,int t){
    int f=x>>1;
    while (f>=2&&v[f]>t)
        v[x]=v[f],x=f,f>>=1;
    v[x]=t;
}
void maxup(int x,int t){
    int f=x>>1;
    while (f>=3&&v[f]<t)
        v[x]=v[f],x=f,f>>=1;
    v[x]=t;
}
void insert(int t){
    if (num==1){
        v[++num]=t;
        return;
    }
    int j=judge(++num);
    if (j==2){
        int at=minsame(num);
        if (v[at]<t){
            v[num]=v[at];
            maxup(at,t);
        }
        else
            minup(num,t);
    }
    else{
        int at=maxsame(num);
        if (v[at]>t){
            v[num]=v[at];
            minup(at,t);
        }
        else
            maxup(num,t);
    }
}
void delmin(){
    int t=v[num--],x=2,s=4;
    while (s<=num){
        if (s+1<=num&&v[s+1]<v[s])
            s++;
        v[x]=v[s],x=s,s<<=1;
    }
    int at=minsame(x);
    if (v[at]<t){
        v[x]=v[at];
        maxup(at,t);
    }
    else
        minup(x,t);
}
void delmax(){
    int t=v[num--],x=3,s=6;
    while (s<=num){
        if (s+1<=num&&v[s+1]>v[s])
            s++;
        v[x]=v[s],x=s,s<<=1;
    }
    int at=maxsame(x);
    if ((at<<1)<=num){
        at<<=1;
        if (at+1<=num&&v[at+1]>v[at])
            at++;
    }
    if (v[at]>t){
        v[x]=v[at];
        minup(at,t);
    }
    else
        maxup(x,t);
}
main()
{
    num=1;
    int n;
    while (scanf("%d",&n)==1){
        if (n==1){
            scanf("%d",&n);
            insert(n);
        }
        else if (n==2){
            if (num==2){
                printf("%d\n",v[2]);
                delmin();
            }
            else{
                printf("%d\n",v[3]);
                delmax();
            }
        }
        else{
            printf("%d\n",v[2]);
            delmin();
        }
    }
    return 0;
}
