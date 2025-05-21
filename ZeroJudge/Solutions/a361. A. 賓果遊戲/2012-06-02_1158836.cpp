#include <cstdio>

struct Node {int i,j;} A[26],B[26];
bool a[5][5],b[5][5];
bool check(bool map[5][5]){
    for (int i=0;i<5;i++){
        bool tag=true;
        for (int j=0;j<5;j++)
            tag&=map[i][j];
        if (tag)
            return true;
        tag=true;
        for (int j=0;j<5;j++)
            tag&=map[j][i];
        if (tag)
            return true;
    }
    bool tag=true;
    for (int i=0;i<5;i++)
        tag&=map[i][i];
    if (tag)
        return true;
    tag=true;
    for (int i=0;i<5;i++)
        tag&=map[4-i][i];
    return tag;
}
int c[25];
void work(){
    for (int i=0;i<25;i++){
        a[A[c[i]].i][A[c[i]].j]=b[B[c[i]].i][B[c[i]].j]=true;
        bool ca=check(a),cb=check(b);
        if (ca&&cb){
            puts("0");
            break;
        }
        else if (ca){
            puts("1");
            break;
        }
        else if (cb){
            puts("2");
            break;
        }
    }
}
int main()
{
    int cases,tmp;
    scanf("%d",&cases);
    while (cases--){
        for (int i=0;i<5;i++)
            for (int j=0;j<5;j++)
                a[i][j]=b[i][j]=false;
        for (int i=0;i<5;i++)
            for (int j=0;j<5;j++)
                scanf("%d",&tmp),A[tmp].i=i,A[tmp].j=j;
        for (int i=0;i<5;i++)
            for (int j=0;j<5;j++)
                scanf("%d",&tmp),B[tmp].i=i,B[tmp].j=j;
        for (int i=0;i<25;i++)
            scanf("%d",&c[i]);
        work();
    }
}
