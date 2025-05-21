#include <cstdio>

int Q[270000][9],from[270000],method[270000];
bool use[270000]={};
int move[9][5]={{0,1,3,4}
               ,{0,1,2}
               ,{1,2,4,5}
               ,{0,3,6}
               ,{1,3,4,5,7}
               ,{2,5,8}
               ,{3,4,6,7}
               ,{6,7,8}
               ,{4,5,7,8}};
int num[9]={4,3,4,3,5,3,4,3,4};
void change(int a[],int b[],int no){
    for (int i=0;i<9;i++)
        b[i]=a[i];
    for (int i=0;i<num[no];i++){
        b[move[no][i]]--;
        if (b[move[no][i]]<0)
            b[move[no][i]]+=4;
    }
}
int get(int a[]){
    int sum=0;
    for (int i=0;i<9;i++)
        sum=(sum<<2)+a[i];
    return sum;
}
void Build(){
    int l=0,r=1;
    for (int i=0;i<9;i++)
        Q[0][0]=0;
    use[0]=true;
    while (l<r){
        int now=get(Q[l]);
        /*puts("now");
        for (int i=0;i<9;i++)
            printf("%d ",Q[l][i]);
        puts("");
        getchar();*/
        for (int i=0;i<9;i++){
            change(Q[l],Q[r],i);
            int v=get(Q[r]);
            /*puts("to");
            for (int j=0;j<9;j++)
                printf("%d ",Q[r][j]);
            puts("");*/
            if (!use[v]){
                use[v]=true;
                from[v]=now;
                method[v]=i;
                r++;
            }
        }
        l++;
    }
}
int main()
{
    Build();
    int cases,a[9],ans[1000],ansnum;
    scanf("%d",&cases);
    while (cases--){
        for (int i=0;i<9;i++)
            scanf("%d",&a[i]);
        int at=get(a);
        ansnum=0;
        while (at!=0){
            ans[ansnum++]=method[at];
            at=from[at];
        }
        for (int i=ansnum-1;i>=0;i--)
            printf((i)?"%d ":"%d",ans[i]+1);
        puts("");
    }    
}
