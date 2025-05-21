#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int A[1000000],qa[1000000],qb[1000000],*p[3000000],sum[3000000]={};
int mod=65536,all=mod<<1;
inline int findmod(int *x){
    int t=(*x);
    bool negative=(t<0);
    if (t<0)
        t=-t;
    t&=(mod-1);
    return ((negative)?-t:t)+mod;
}
inline int finddivide(int *x){
    int t=(*x);
    bool negative=(t<0);
    if (t<0)
        t=-t;
    t>>=16;
    return ((negative)?-t:t)+mod;
}
vector <int *> box[140000];
void radix_sort(int *a[],int n){
    for (int i=0;i<n;i++){
        int t=findmod(a[i]);
        box[t].push_back(a[i]);
    }
    int num=0;
    for (int i=0;i<all;i++){
        int l=box[i].size();
        for (int j=0;j<l;j++)
            a[num++]=box[i][j];
        box[i].clear();
    }
    for (int i=0;i<n;i++){
        int t=finddivide(a[i]);
        box[t].push_back(a[i]);
    }
    num=0;
    for (int i=0;i<all;i++){
        int l=box[i].size();
        for (int j=0;j<l;j++)
            a[num++]=box[i][j];
    }
}
int input(){
    char c=getchar();
    while (c!='-'&&(c>'9'||c<'0')) c=getchar();
    bool negative=(c=='-');
    int x=(negative)?0:c-48;
    c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return (negative)?-x:x;
}
int main()
{
    //clock_t st,ed;
    //st=clock();
    int n,q,num=0;
    n=input(),q=input();
    for (int i=0;i<n;i++)
        A[i]=input();
    for (int i=0;i<q;i++){
        qa[i]=input(),qb[i]=input();
        p[num++]=&qa[i];
    }
    for (int i=0;i<n;i++)
        p[num++]=&A[i];
    for (int i=0;i<q;i++)
        p[num++]=&qb[i];
    radix_sort(p,num);
    /*for (int i=0;i<num;i++)
        printf("%d ",*p[i]);
    puts("");*/
    for (int i=0;i<num;i++)
        (*p[i])=i;
    for (int i=0;i<n;i++)
        sum[A[i]]++;
    for (int i=0;i<num;i++)
        sum[i]+=sum[i-1];
    for (int i=0;i<q;i++){
        int v=sum[qb[i]]-sum[qa[i]];
        if (v)
            printf("%d\n",v);
        else
            puts("The candies are too short");
    }
    //ed=clock();
    //cout<<ed-st<<"ms\n";
    //while (1);
}
