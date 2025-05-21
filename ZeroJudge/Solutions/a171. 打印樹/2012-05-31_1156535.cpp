#include <cstdio>

int num;
struct Node{
    int l,r,v;
} tree[60000];
void newnode(int x,int v){
    tree[x].l=tree[x].r=-1;
    tree[x].v=v;
}
void insert(int x){
    int at=0;
    while (1){
        if (tree[at].v==x)
            return;
        else if (tree[at].v<x){
            if (tree[at].r==-1){
                newnode(num,x);
                tree[at].r=num++;
                return;
            }
            at=tree[at].r;
        }
        else if (tree[at].v>x){
            if (tree[at].l==-1){
                newnode(num,x);
                tree[at].l=num++;
                return;
            }
            at=tree[at].l;
        }
    }
}
int maxd;
void dfs(int x,int d){
    if (x==-1)
        return;
    if (d>maxd)
        maxd=d;
    dfs(tree[x].l,d+1);
    dfs(tree[x].r,d+1);
}
char map[3000][6000];
int end[3000];
void printdfs(int x,int l,int i,int j){
    map[i][j]='X';
    if (tree[x].l!=-1){
        int ii=i+1,jj=j-1;
        for (int k=0;k<l-1;k++)
            map[ii][jj]='/',ii++,jj--;
        printdfs(tree[x].l,l>>1,i+l,j-l);
    }
    if (tree[x].r!=-1){
        int ii=i+1,jj=j+1;
        for (int k=0;k<l-1;k++)
            map[ii][jj]='\\',ii++,jj++;
        printdfs(tree[x].r,l>>1,i+l,j+l);
    }
}
void work(int full){
    int st=2147483647;
    for (int i=0;i<full;i++){
        int j=0;
        while (map[i][j]==' ')
            j++;
        if (j<st)
            st=j;
    }
    for (int i=0;i<full;i++){
        int j=(full<<1)-1;
        while (map[i][j]==' ')
            j--;
        end[i]=j;
    }
    for (int i=0;i<full;i++){
        for (int j=st;j<=end[i];j++)
            putchar(map[i][j]);
        puts("");
    }
}
int main()
{
    int n;
    while (scanf("%d",&n)==1){
        int tmp;
        scanf("%d",&tmp);
        newnode(0,tmp);
        num=1;
        for (int i=1;i<n;i++){
            scanf("%d",&tmp);
            insert(tmp);
        }
        maxd=0;
        dfs(0,0);
        int full=1<<maxd;
        for (int i=0;i<full;i++)
            for (int j=0;j<(full<<1);j++)
                map[i][j]=' ';
        printdfs(0,full>>1,0,full);
        work(full);
    }
}
