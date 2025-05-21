#include <cstdio>
#include <algorithm>

struct Node{
    int x,y;
} node[10000];
bool cmp(Node i,Node j){
    if (i.x!=j.x)
        return i.x<j.x;
    return i.y<j.y;
}
int tree[400],method[400];
void init(int at,int l,int r){ 
    tree[at]=0;
    method[at]=0;
    if (l==r)
        return;
    int mid=(l+r)/2;
    init(2*at,l,mid);
    init(2*at+1,mid+1,r);
}
int maxx,sum;
void update(int at,int l,int r,int x,int v1,int v2){
    if (l==r){
        if (v1>tree[at])
            tree[at]=v1,method[at]=v2;
        else if (v1==tree[at])
            method[at]+=v2;
        return;
    }
    int mid=(l+r)/2;
    if (x<=mid)
        update(2*at,l,mid,x,v1,v2);
    if (x>=mid+1)
        update(2*at+1,mid+1,r,x,v1,v2);
    if (tree[2*at]>tree[2*at+1])
        tree[at]=tree[2*at],method[at]=method[2*at];
    else if (tree[2*at]<tree[2*at+1])
        tree[at]=tree[2*at+1],method[at]=method[2*at+1];
    else
        tree[at]=tree[2*at],method[at]=method[2*at]+method[2*at+1];
}
void query(int at,int l,int r,int dl,int dr){
    if (dl<=l&&r<=dr){
        if (tree[at]>maxx){
            maxx=tree[at];
            sum=method[at];
        }
        else if (tree[at]==maxx)
            sum+=method[at];
        return;
    }
    int mid=(l+r)/2;
    if (dl<=mid)
        query(2*at,l,mid,dl,dr);
    if (dr>=mid+1)
        query(2*at+1,mid+1,r,dl,dr);
}
inline int input(){
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
    int n,m,cases=0;
    while (1){
        n=input(),m=input();
        if (n==-1&&m==-1)
            break;
        int num=0;
        while (1){
            node[num].x=input();
            node[num].y=input();
            if (node[num].x==0&&node[num].y==0)
                break;
            num++;
        }
        std::stable_sort(node,node+num,cmp);
        init(1,1,m);
        int MAX=0,SUM=0;
        for (int i=0;i<num;i++){
            int now=node[i].y;
            maxx=0,sum=0;
            query(1,1,m,1,now);
            if (maxx==0)
                maxx=1,sum=1;
            else
                maxx++;
            if (maxx>MAX)
                MAX=maxx,SUM=sum;
            else if (maxx==MAX)
                SUM+=sum;
            update(1,1,m,now,maxx,sum);
        }
        printf("CASE#%d: %d %d\n",++cases,MAX,SUM);
    }
}
