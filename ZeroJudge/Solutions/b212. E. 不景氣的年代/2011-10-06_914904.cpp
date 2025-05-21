#include <cstdio>
#include <algorithm>

struct Node {int a,b,c;} p[5001];
int tree[10004];
bool use[5001];
bool cmp(int i,int j){
    return p[i].a<p[j].a;
}
bool cmp2(int i,int j){
    return p[i].b<p[j].b;
}
void insert(int x){
    while (x<=10003){
        tree[x]++;
        x+=(-x)&x;
    }
}
int search(int x){
    int sum=0;
    while (x>0){
        sum+=tree[x];
        x-=(-x)&x;
    }
    return sum;
}
int main()
{
    int cases,n,t[5001],t2[5001],ans;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d",&n);
        for (int i=0;i<n;i++){
            scanf("%d %d %d",&p[i].a,&p[i].b,&p[i].c);
            t[i]=t2[i]=i;
            use[i]=false;
            p[i].a++,p[i].b++,p[i].c++;
        }
        std::stable_sort(t,t+n,cmp);
        std::stable_sort(t2,t2+n,cmp2);
        ans=0;
        for (int j=0;j<n;j++){
            for (int i=1;i<=10003;i++)
                tree[i]=0;
            int V=10003-p[t[j]].a;
            use[t[j]]=true;
            for (int k=0;k<n;k++)
                if (use[t2[k]]){
                    if (V-p[t2[k]].b<1)
                        break;
                    insert(p[t2[k]].c);
                    int X=search(V-p[t2[k]].b);
                    if (X>ans)
                        ans=X;
                }
        }
        printf("%d\n",ans);
    }
    return 0;
}
