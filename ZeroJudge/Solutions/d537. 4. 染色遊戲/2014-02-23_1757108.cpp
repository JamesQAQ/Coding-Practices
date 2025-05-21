#include <stdio.h>

#define Y 1
#define R 2
#define O 3
#define B 4
#define G 5
#define P 6
#define D 7

int cnt[8]={};

struct NODE{
    int x,y,v,t;
} Q[2000000];

int n;

bool in(int x,int y){
    return x>=0&&y>=0&&x<n&&y<n;
}
int map[1000][1000];

void replace(int x,int y,int v){
    cnt[map[x][y]]--;
    map[x][y]|=v;
    cnt[map[x][y]]++;
}

int move[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

void get(char c,int &at){
    if (c=='Y') at=Y;
    if (c=='B') at=B;
    if (c=='R') at=R;
    if (c=='O') at=O;
    if (c=='D') at=D;
    if (c=='P') at=P;
    if (c=='G') at=G;
}

int main()
{
    int x,y,v,t;
    char c;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            map[i][j]=0;
    for (int i=1;i<8;i++)
        cnt[i]=0;
    int l=0,r=0;
    for (int i=0;i<3;i++){
        scanf(" %c %d %d",&c,&x,&y);
        Q[r].x=x,Q[r].y=y;
        get(c,Q[r].v);
        Q[r].t=0;
        
        replace(x,y,Q[r].v);
        
        r++;
    }
    int limit=1;
    
    int maxx=0,at;
    
    scanf(" %c",&c);
    get(c,at);
    
    while (l<r){
        while (l<r&&Q[l].t<limit){
            x=Q[l].x,y=Q[l].y,v=Q[l].v,t=Q[l].t;
            l++;
            
            for (int i=0;i<8;i++){
                int xx=x+move[i][0];
                int yy=y+move[i][1];
                if (in(xx,yy)&&(map[xx][yy]&v)==0){
                    replace(xx,yy,v);
                    Q[r].x=xx;
                    Q[r].y=yy;
                    Q[r].v=v;
                    Q[r].t=t+1;
                    r++;
                }
            }
        }
        if (cnt[at]>maxx)
            maxx=cnt[at];
        limit++;
    }
    printf("%d\n",maxx);
}
