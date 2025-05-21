#include <cstdio>
#include <queue>

int pow2[13],no[4][4][4][4],st,ed;
int move[10][4]={{12,12,12,12}
                ,{2,4,12,12}
                ,{1,3,5,12}
                ,{2,6,12,12}
                ,{1,5,7,12}
                ,{2,4,6,8}
                ,{3,5,9,12}
                ,{4,8,12,12}
                ,{5,7,9,12}
                ,{6,8,12,12}};
int pass[10][4]={{12,12,12,12}
                ,{0,2,12,12}
                ,{0,1,3,12}
                ,{1,4,12,12}
                ,{2,5,7,12}
                ,{3,5,6,8}
                ,{4,6,9,12}
                ,{7,10,12,12}
                ,{8,10,11,12}
                ,{9,11,12,12}};
bool run[4096],win[4096];
void build_map(){
    no[1][0][1][1]=no[1][1][1][0]=0;
    no[2][0][2][1]=no[2][1][2][0]=1;
    no[0][1][1][1]=no[1][1][0][1]=2;
    no[1][1][2][1]=no[2][1][1][1]=3;
    no[2][1][3][1]=no[3][1][2][1]=4;
    no[1][1][1][2]=no[1][2][1][1]=5;
    no[2][1][2][2]=no[2][2][2][1]=6;
    no[1][2][0][2]=no[0][2][1][2]=7;
    no[1][2][2][2]=no[2][2][1][2]=8;
    no[2][2][3][2]=no[3][2][2][2]=9;
    no[1][2][1][3]=no[1][3][1][2]=10;
    no[2][2][2][3]=no[2][3][2][2]=11;
}
bool BFS(int s){
    bool use[12]={};
    std::queue <int> Q;
    use[st]=true;
    Q.push(st);
    while (!Q.empty()){
        int x=Q.front();
        Q.pop();
        if (x==ed)
            return true;
        for (int i=0;i<4;i++){
            int to=move[x][i];
            if (to==12||use[to])
                continue;
            if ((pow2[pass[x][i]]&s)==0){
                use[to]=true;
                Q.push(to);
            }
        }
    }
    return false;
}
bool cnt(int s){
    if (!run[s]){
        run[s]=true;
        win[s]=false;
        if (BFS(s)){
            win[s]=false;
            return win[s];
        }
        for (int i=0;i<12;i++)
            if (pow2[i]&s)
                if (!cnt(s-pow2[i])){
                    win[s]=true;
                    return win[s];
                }
    }
    return win[s];
}
int main()
{
    pow2[0]=1;
    for (int i=1;i<=12;i++)
        pow2[i]=pow2[i-1]<<1;
    build_map();
    int cases,r,x1,y1,x2,y2;
    scanf("%d",&cases);
    for (int i=1;i<=cases;i++){
        scanf("%d %d %d",&st,&ed,&r);
        int s=pow2[12]-1;
        for (int j=0;j<r;j++){
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            s-=pow2[no[x1][y1][x2][y2]];
        }
        printf("Case %d: ",i);
        if (BFS(s))
            puts("No Cheese!");
        else{
            for (int j=0;j<=s;j++)
                run[j]=false;
            puts((cnt(s))?"SOHA":"TARA");
        }
    }
}
