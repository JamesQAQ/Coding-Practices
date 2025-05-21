#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

struct Que {int x,y,no;} question[100000];
bool cmp(Que i,Que j){
    return i.y<j.y;
}
struct Node {int to[26],fail,v;} trie[100001];
int trienum,F[100000],end[100000],strnum;
void newnode(int x,int v){
    for (int i=0;i<26;i++)
        trie[x].to[i]=-1;
    trie[x].v=v;
}
void buildtrie(char s[]){
    int len=strlen(s);
    while (s[len-1]!='P')
        s[len-1]=0,len--;
    int at=0;
    newnode(0,-1);
    F[0]=-1;
    trienum=1;
    strnum=0;
    for (int i=0;s[i];i++){
        if (s[i]=='B')
            at=F[at];
        else if (s[i]=='P')
            end[strnum++]=at;
        else{
            int v=s[i]-'a';
            if (trie[at].to[v]==-1){
                newnode(trienum,v);
                trie[at].to[v]=trienum++;
            }
            F[trie[at].to[v]]=at;
            at=trie[at].to[v];
        }
    }
}
struct Queue {int x,f;} Q[100001];
std::vector <int> path[100001];
void buildAC(){
    trie[0].fail=-1;
    int l=0,r=0;
    for (int i=0;i<26;i++)
        if (trie[0].to[i]!=-1){
            Q[r].x=trie[0].to[i];
            Q[r].f=0;
            r++;
        }
    while (l<r){
        int x=Q[l].x,f=Q[l].f,v=trie[x].v;
        l++;
        int father=trie[f].fail;
        while (father!=-1&&trie[father].to[v]==-1)
            father=trie[father].fail;
        if (father==-1)
            trie[x].fail=0;
        else
            trie[x].fail=trie[father].to[v];
        path[trie[x].fail].push_back(x);
        //printf("x %d fail %d\n",x,trie[x].fail);
        for (int i=0;i<26;i++){
            if (trie[x].to[i]!=-1){
                Q[r].x=trie[x].to[i];
                Q[r].f=x;
                r++;
            }
        }
    }    
}
int tag=0,L[100001],R[100001];
void dfs(int x,int f){
    L[x]=tag++;
    //printf("dfs %d %d tag %d\n",x,f,tag);
    int p=path[x].size();
    for (int i=0;i<p;i++){
        int to=path[x][i];
        if (to!=f)
            dfs(to,x);
    }
    R[x]=tag-1;
}
int tree[400000],SUM,ans[100000];
void query(int at,int l,int r,int dl,int dr){
    if (dl<=l&&r<=dr){
        //printf("l %d r %d at %d tree %d\n",l,r,at,tree[at]);
        SUM+=tree[at];
        return;
    }
    int mid=(l+r)/2;
    if (dl<=mid)
        query(2*at,l,mid,dl,dr);
    if (dr>=mid+1)
        query(2*at+1,mid+1,r,dl,dr);
}
void plus(int at,int l,int r,int x,int p){
    tree[at]+=p;
    //printf("l %d r %d at %d += %d\n",l,r,at,p);
    if (l==r)
        return;
    int mid=(l+r)/2;
    if (x<=mid)
        plus(2*at,l,mid,x,p);
    if (x>=mid+1)
        plus(2*at+1,mid+1,r,x,p); 
}
int main()
{
    char s[100001];
    int q;
    scanf("%s",s);
    buildtrie(s);
    buildAC();
    dfs(0,-1);
    scanf("%d",&q);
    for (int i=0;i<q;i++)
        scanf("%d %d",&question[i].x,&question[i].y),question[i].no=i;
    std::stable_sort(question,question+q,cmp);
    //for (int i=0;i<trienum;i++)
    //    printf("%d %d %c %d %d\n",i,trie[i].fail,trie[i].v+'a',L[i],R[i]);
    int at=0,cnt=0,no=0;
    for (int i=0;i<q;i++){
        //printf("x %d y %d\n",question[i].x,question[i].y);
        while (s[no]&&cnt!=question[i].y){
            if (s[no]=='P')
                cnt++;
            else if (s[no]=='B'){
                plus(1,0,tag-1,L[at],-1);
                at=F[at];
            }
            else{
                at=trie[at].to[s[no]-'a'];
                plus(1,0,tag-1,L[at],1);
                //printf("plus %d\n",L[at]);
            }
            no++;
        }
        SUM=0;
        //printf("query x %d y %d %d %d %d\n",question[i].x,question[i].y,L[end[question[i].x-1]],R[end[question[i].x-1]],SUM);
        query(1,0,tag-1,L[end[question[i].x-1]],R[end[question[i].x-1]]);
        ans[question[i].no]=SUM;
    }
    for (int i=0;i<q;i++)
        printf("%d\n",ans[i]);
    //while (1);
}
/*
aPaPBbP
3
1 2
1 3
2 3
*/
