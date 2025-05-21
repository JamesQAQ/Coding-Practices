#include <cstdio>
#include <iostream>

struct Node {int l,r,v,in,f,t,mini,maxx;} tree[31];//1 black -1 red
int at[201],num,top[31],tn,ans,sum[31],root;
void topo_sort(int x){
    top[tn++]=x;
    if (tree[x].l!=-1)
        topo_sort(tree[x].l);
    if (tree[x].r!=-1)
        topo_sort(tree[x].r);
}
bool judge(int x){
    if (tree[x].l!=-1&&tree[tree[x].l].t>tree[x].t)
        std::swap(tree[x].l,tree[x].r);
    if (tree[x].r!=-1&&tree[tree[x].r].t<tree[x].t)
        std::swap(tree[x].l,tree[x].r);
    int l=tree[x].l,r=tree[x].r;
    if (l==-1&&r==-1)
        tree[x].mini=tree[x].maxx=tree[x].t;
    else if (r==-1){
        if (!judge(l))
            return false;
        if (tree[l].maxx>tree[x].t)
            return false;
        tree[x].maxx=tree[x].t;
        tree[x].mini=tree[l].mini;
    }
    else if (l==-1){
        if (!judge(r))
            return false;
        if (tree[r].mini<tree[x].t)
            return false;
        tree[x].mini=tree[x].t;
        tree[x].maxx=tree[r].maxx;
    }
    else{
        if (!judge(l))
            return false;
        if (!judge(r))
            return false;
        if (tree[l].maxx>tree[x].t||tree[r].mini<tree[x].t)
            return false;
        tree[x].mini=tree[l].mini;
        tree[x].maxx=tree[r].maxx;
    }
    return true;
}
bool ok(int x){
    if (tree[x].l!=-1){
        if (!ok(tree[x].l))
            return false;
    }
    if (tree[x].r!=-1){
        if (!ok(tree[x].r))
            return false;
    }
    if (tree[x].l==-1||tree[x].r==-1){
        if (tree[x].l!=-1&&sum[tree[x].l]!=1)
            return false;
        if (tree[x].r!=-1&&sum[tree[x].r]!=1)
            return false;
        sum[x]=1;
        if (tree[x].v==1)
            sum[x]++;
    }
    else{
        if (sum[tree[x].l]!=sum[tree[x].r])
            return false;
        sum[x]=sum[tree[x].l];
        if (tree[x].v==1)
            sum[x]++;
    }
    return true;
}

void dfs(int x){
    if (x==tn){
        /*for (int i=0;i<tn;i++){
            printf("%d:%c ",i,(tree[i].v==1)?'b':'r');
        }
        puts("");*/
        if (ok(root)){
            ans++;
            //puts("k");
        }
        return;
    }
    int i=top[x];
    if (x==0){
        sum[i]=1;
        tree[i].v=1;
        dfs(x+1);
    }
    else{
        if (tree[tree[i].f].v!=-1){
            tree[i].v=-1;
            dfs(x+1);
        }
        tree[i].v=1;
        dfs(x+1);
    }
}
int main()
{
    int n,a,b,t=0;
    while (scanf("%d",&n)==1){
        if (n==1){
            printf("Case %d:1\n",++t);
            continue;
        }
        for (int i=0;i<=200;i++)
            at[i]=-1;
        num=0;
        for (int i=0;i<n-1;i++){
            scanf("%d %d",&a,&b);
            a+=100,b+=100;
            if (at[a]==-1){
                at[a]=num;
                tree[num].l=tree[num].r=-1;
                tree[num].v=tree[num].in=0;
                tree[num].t=a;
                num++;
            }
            if (at[b]==-1){
                at[b]=num;
                tree[num].l=tree[num].r=-1;
                tree[num].v=tree[num].in=0;
                tree[num].t=b;
                num++;
            }
            a=at[a];
            b=at[b];
            if (tree[a].l==-1)
                tree[a].l=b;
            else
                tree[a].r=b;
            tree[b].in++,tree[b].f=a;
        }
        for (int i=0;i<num;i++)
            if (tree[i].in==0){
                root=i;
                break;
            }
        if (!judge(root)){
            printf("Case %d:0\n",++t);
            continue;
        }
        tn=0;
        topo_sort(root);
        ans=0;
        dfs(0);
        printf("Case %d:%d\n",++t,ans);
    }
    return 0;
}
