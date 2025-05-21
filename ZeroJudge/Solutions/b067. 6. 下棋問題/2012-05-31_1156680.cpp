#include <cstdio>
#include <algorithm>

bool connect[5000][5000];
struct Node{
    int x,y,no;
} node[5000];
bool cmp(Node i,Node j){
    return i.y>j.y;
}
void one(int a[],int b[],int &top,int no){
    while (top&&node[no].x<a[top-1])
        top--;
    a[top]=node[no].x,b[top]=node[no].no;
    top++;
}
void two(int a[],int b[],int &top,int no){
    while (top&&node[no].x>a[top-1])
        top--;
    a[top]=node[no].x,b[top]=node[no].no;
    top++;
}
void three(int a[],int b[],int &top,int no){
    if (top==0||node[no].x>a[top-1]){
        a[top]=node[no].x,b[top]=node[no].no;
        top++;
    }
}
void four(int a[],int b[],int &top,int no){
    if (top==0||node[no].x<a[top-1]){
        a[top]=node[no].x,b[top]=node[no].no;
        top++;
    }
}
void build(int b[][5000],int top[],int no){
    for (int i=0;i<4;i++)
        for (int j=0;j<top[i];j++)
            connect[no][b[i][j]]=connect[b[i][j]][no]=true;
}
int cut(int b[][5000],int top[]){
    int sum=0;
    for (int i=0;i<top[0];i++)
        for (int j=0;j<top[2];j++)
            if (connect[b[0][i]][b[2][j]]||connect[b[2][j]][b[0][i]])
                connect[b[0][i]][b[2][j]]=connect[b[2][j]][b[0][i]]=false,sum++;  
    for (int i=0;i<top[1];i++)
        for (int j=0;j<top[3];j++)
            if (connect[b[1][i]][b[3][j]]||connect[b[3][j]][b[1][i]])
                connect[b[1][i]][b[3][j]]=connect[b[3][j]][b[1][i]]=false,sum++;
    return sum;
}
int main()
{
    int n,stack[4][5000],X[5000],Y[5000],b[4][5000];
    while (scanf("%d",&n)==1){
        for (int i=0;i<n;i++)
            scanf("%d %d",&node[i].x,&node[i].y),node[i].no=i,X[i]=node[i].x,Y[i]=node[i].y;
        std::stable_sort(node,node+n,cmp);
        long long now=0,A[2]={};
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                connect[i][j]=false;
        for (int i=0;i<n;i++){
            int top[4]={},x=X[i],y=Y[i];
            for (int j=0;j<n;j++)
                if (node[j].no<i){
                    if (node[j].x>x&&node[j].y>y)
                        one(stack[0],b[0],top[0],j);
                    else if (node[j].x<x&&node[j].y>y)
                        two(stack[1],b[1],top[1],j);
                    else if (node[j].x<x&&node[j].y<y)
                        three(stack[2],b[2],top[2],j);
                    else if (node[j].x>x&&node[j].y<y)
                        four(stack[3],b[3],top[3],j);
                }
            now+=top[0]+top[1]+top[2]+top[3];
            build(b,top,i);
            now-=cut(b,top);
            A[i&1]+=now;
        }
        printf("%lld %lld\n",A[0],A[1]);
    }
}
