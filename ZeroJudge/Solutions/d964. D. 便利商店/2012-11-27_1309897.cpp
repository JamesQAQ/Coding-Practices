#include <stdio.h>
#include <algorithm>

int R[30001],C[30001],t[20000];
struct Line{
    int l,r,at,v;
} line[20000];
bool cmp(int i,int j){
    return line[i].at<line[j].at;
}
inline int min(int a,int b){
    return (a<b)?a:b;
}
inline int max(int a,int b){
    return (a>b)?a:b;
}
int tree[1000000],mark[1000000],loca[1000000];
void init(int at,int l,int r){
    mark[at]=0;
    if (l==r){
        loca[at]=l;
        tree[at]=C[l];
        return;
    }
    int mid=(l+r)/2;
    init(2*at,l,mid);
    init(2*at+1,mid+1,r);
    if (tree[2*at]>=tree[2*at+1])
        tree[at]=tree[2*at],loca[at]=loca[2*at];
    else
        tree[at]=tree[2*at+1],loca[at]=loca[2*at+1];
}
inline void spread(int at){
    mark[2*at]+=mark[at];
    mark[2*at+1]+=mark[at];
    tree[2*at]+=mark[at];
    tree[2*at+1]+=mark[at];
    mark[at]=0;
}
void update(int at,int l,int r,Line &tmp){
    if (tmp.l<=l&&r<=tmp.r){
        tree[at]+=tmp.v;
        mark[at]+=tmp.v;
        return;
    }
    if (mark[at])
        spread(at);
    int mid=(l+r)/2;
    if (tmp.l<=mid)
        update(2*at,l,mid,tmp);
    if (tmp.r>=mid+1)
        update(2*at+1,mid+1,r,tmp);
    if (tree[2*at]>=tree[2*at+1])
        tree[at]=tree[2*at],loca[at]=loca[2*at];
    else
        tree[at]=tree[2*at+1],loca[at]=loca[2*at+1];
}
inline int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=((x<<3)+(x<<1))+c-48,c=getchar();
    return x;
}
int main()
{
    int cases,r,c,n;
    cases=input();
    while (cases--){
        r=input(),c=input(),n=input();
        for (int i=1;i<=r;i++)
            R[i]=input();
        for (int i=1;i<=c;i++)
            C[i]=input();
        int tr,tc,td,tp,num=0;
        for (int i=0;i<n;i++){
            tr=input(),tc=input(),td=input(),tp=input();
            int ttl=max(tc-td,1),ttr=min(tc+td,c);
            t[num]=num,line[num].l=ttl,line[num].r=ttr,line[num].at=max(tr-td,1),line[num].v=-tp,num++;
            t[num]=num,line[num].l=ttl,line[num].r=ttr,line[num].at=min(tr+td,r)+1,line[num].v=tp,num++;
        }
        std::stable_sort(t,t+num,cmp);
        init(1,1,c);
        int at=0,ansr,ansc,ans;
        bool first=true;
        for (int i=1;i<=r;i++){
            while (at<num&&line[t[at]].at<=i)
                update(1,1,c,line[t[at]]),at++;
            int maxv=tree[1]+R[i],tr=i,tc=loca[1];
            if (first||maxv>ans){
                ans=maxv;
                ansr=tr;
                ansc=tc;
                first=false;
            }
        }
        if (ans>0)
            printf("%d %d %d\n",ansr,ansc,ans);
        else
            puts("1 1 0");
    }
}
