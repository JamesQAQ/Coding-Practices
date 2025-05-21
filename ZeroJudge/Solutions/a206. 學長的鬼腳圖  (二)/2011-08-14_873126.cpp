#include <cstdio>
#include <iostream>

int n,m,x,a[1000][64];
char map[65][300];

bool judge(int k){
    for (int i=0;i<m;i++){
        int j=0;
        while (j<n){
            if (map[j][i]!='-'){
                int f=j++;
                while (map[j][i]==map[j-1][i])
                    j++;
                if (a[k][f]>a[k][j-1])
                    std::swap(a[k][f],a[k][j-1]);
            }
            else
                j++;
        }
    }
    for (int i=0;i<n-1;i++)
        if (a[k][i]>a[k][i+1])
            return false;
    return true;
}
bool ok(){
    for (int i=0;i<x;i++)
        if (!judge(i))
            return false;
    return true;
}
int main()
{
    while (scanf("%d %d",&n,&m)==2){
        scanf("%d",&x);
        for (int i=0;i<x;i++)
            for (int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        for (int i=0;i<n;i++)
            scanf("%s",map[i]);
        for (int i=0;i<m;i++)
            map[n+1][i]='-';
        (ok())?puts("This is a reliable sorting ghost leg!"):puts("So sad......This is just a  ghost leg.");
    }
    return 0;
}
