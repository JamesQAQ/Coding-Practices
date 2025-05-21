#include <cstdio>
#include <cstring>

char a[801],b[801];
int limit[26],lena,lenb,dL,dR,dl,dr,value,At,_at;

struct Node {int t[3200];} tree[3200];
void init(Node &T,int at,int l,int r){
    T.t[at]=0;
    if (l==r)
        return;
    int mid=(l+r)/2;
    init(T,2*at,l,mid);
    init(T,2*at+1,mid+1,r);
}
void Init(int at,int l,int r){
    init(tree[at],1,0,lenb);
    if (l==r)
        return;
    int mid=(l+r)/2;
    Init(2*at,l,mid);
    Init(2*at+1,mid+1,r);
}
void search(Node &T,int at,int l,int r){
    if (l>=dl&&r<=dr){
        if (T.t[at]>value)
            value=T.t[at];
        return;
    }
    int mid=(l+r)/2;
    if (mid>=dl)
        search(T,2*at,l,mid);
    if (mid+1<=dr)
        search(T,2*at+1,mid+1,r);
}
void Search(int at,int l,int r){
    if (l>=dL&&r<=dR){
        search(tree[at],1,0,lenb);
        return;
    }
    int mid=(l+r)/2;
    if (mid>=dL)
        Search(2*at,l,mid);
    if (mid+1<=dR)
        Search(2*at+1,mid+1,r);
}
void insert(Node &T,int at,int l,int r){
    if (_at>=l&&_at<=r)
        if (value>T.t[at])
            T.t[at]=value;
    if (l==r)
        return;
    int mid=(l+r)/2;
    if (mid>=_at)
        insert(T,2*at,l,mid);
    if (mid+1<=_at)
        insert(T,2*at+1,mid+1,r);
}
void Insert(int at,int l,int r){
    if (At>=l&&At<=r)
        insert(tree[at],1,0,lenb);
    if (l==r)
        return;
    int mid=(l+r)/2;
    if (mid>=At)
        Insert(2*at,l,mid);
    if (mid+1<=At)
        Insert(2*at+1,mid+1,r);
}
int main()
{
    int k,tmp;
    scanf("%s %s",a,b);
    lena=strlen(a),lenb=strlen(b);
    scanf("%d",&k);
    for (int t=0;t<k;t++){
        for (int i=0;i<26;i++)
            limit[i]=-1;
        char c;
        while (scanf(" %c",&c)){
            if (c=='$')
                break;
            scanf("%d",&tmp);
            limit[c-'A']=tmp;
        }
        Init(1,0,lena);
        int ans=0;
        for (int i=1;i<=lena;i++)
            for (int j=1;j<=lenb;j++)
                if (a[i-1]==b[j-1]){
                    int L=limit[a[i-1]-'A'];
                    dR=i-1,dr=j-1;
                    if (L==-1)
                        dL=dl=0;
                    else{
                        dL=i-1-L,dl=j-1-L;
                        if (dL<0) dL=0;
                        if (dl<0) dl=0;
                    }
                    value=0;
                    Search(1,0,lena);
                    value++;
                    At=i,_at=j;
                    Insert(1,0,lena);
                    if (value>ans)
                        ans=value;
                }
        printf((t)?" %d":"%d",ans);
    }
    puts("");
}
