#include <cstdio>
#include <queue>
#include <iostream>
struct Node {int x,y;} sheep[100],wolf[100],big_sheep[100];
int n,p,q,d,map[1003][1003],cover_sheep,move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool use_wolf[100];

bool void_sight(){
    for (int i=0;i<q;i++){
        int x=big_sheep[i].x,y=big_sheep[i].y;
        for (int j=0;j<=d;j++){
            if (x+j>1001)
                break;
            for (int k=0;j+k<=d;k++){
                if (y+k>1001)
                    break;
                if (map[x+j][y+k]==-2)
                    cover_sheep++;
                if (map[x+j][y+k]>=0)
                    return false;
                map[x+j][y+k]=-1;
            }
            for (int k=0;j+k<=d;k++){
                if (y-k<1)
                    break;
                if (map[x+j][y-k]==-2)
                    cover_sheep++;
                if (map[x+j][y-k]>=0)
                    return false;
                map[x+j][y-k]=-1;
            }
        }
        for (int j=0;j<=d;j++){
            if (x-j<1)
                break;
            for (int k=0;j+k<=d;k++){
                if (y+k>1001)
                    break;
                if (map[x-j][y+k]==-2)
                    cover_sheep++;
                if (map[x-j][y+k]>=0)
                    return false;
                map[x-j][y+k]=-1;
            }
            for (int k=0;j+k<=d;k++){
                if (y-k<1)
                    break;
                if (map[x-j][y-k]==-2)
                    cover_sheep++;
                if (map[x-j][y-k]>=0)
                    return false;
                map[x-j][y-k]=-1;
            }
        }
    }
    return true;
}
bool success(int no){
    std::queue <Node> Q;
    Node temp;
    temp.x=wolf[no].x,temp.y=wolf[no].y;
    int w=0,s=0;
    Q.push(temp);
    while (!Q.empty()){
        temp=Q.front();
        int x=temp.x,y=temp.y;
        Q.pop();
        for (int i=0;i<4;i++){
            int xx=x+move[i][0],yy=y+move[i][1];
            if (map[xx][yy]>=0)
                w++,use_wolf[map[x][y]]=true;
            if (map[xx][yy]==-2)
                s++;
            if (map[xx][yy]!=-1){
                map[xx][yy]=-1;
                temp.x=xx,temp.y=yy;
                Q.push(temp);
            }
        }
    }
    return w<=s;
}
bool ok(){
    for (int i=0;i<n;i++)
        if (!use_wolf[i])
            if (!success(i))
                return false;
    return true;
}
int main()
{
    int cases;
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d %d %d",&n,&p,&q,&d);
        for (int i=1;i<=1001;i++)
            for (int j=1;j<=1001;j++)
                map[i][j]=-3;
        for (int i=0;i<=1002;i++)
            map[0][i]=map[1002][i]=map[i][0]=map[i][1002]=-1;
        for (int i=0;i<n;i++){
            scanf("%d %d",&wolf[i].x,&wolf[i].y);
            wolf[i].x++,wolf[i].y++;
            use_wolf[i]=false;
            map[wolf[i].x][wolf[i].y]=i;
        }
        for (int i=0;i<p;i++){
            scanf("%d %d",&sheep[i].x,&sheep[i].y);
            sheep[i].x++,sheep[i].y++;
            map[sheep[i].x][sheep[i].y]=-2;
        }
        for (int i=0;i<q;i++){
            scanf("%d %d",&big_sheep[i].x,&big_sheep[i].y);
            big_sheep[i].x++,big_sheep[i].y++;
        }
        if (n>p)
            puts("no");
        else{
            cover_sheep=0;
            if (!void_sight())
                puts("no");
            else if (n>p-cover_sheep)
                puts("no");
            else
                (ok())?puts("yes"):puts("no");
        }
    }
    return 0;
}
