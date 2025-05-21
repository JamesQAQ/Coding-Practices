#include <cstdio>
using namespace std;

int f[100][2][2]={{{0,1},{1,1}}},num,no[100]={1};
int search(int x){
    for (int i=0;i<num;i++)
        if (no[i]==x)
            return i;
    return -1;
}
void count(int x){
    int L=x/2,R=x-L,temp;
    no[num]=x;
    x=num++;
    temp=search(L);
    if (temp==-1){
        count(L);
        temp=search(L);
    }
    L=temp;
    temp=search(R);
    if (temp==-1){
        count(R);
        temp=search(R);
    }
    R=temp;
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++){
            int sum=0;
            for (int k=0;k<2;k++)
                sum+=f[L][i][k]*f[R][k][j];
            f[x][i][j]=sum%10000;
        }
}
int main()
{
    int n;
    while (scanf("%d",&n)==1){
        if (n<=1){
            puts("1");
            continue;
        }
        num=1;
        count(n);
        int p=search(n);
        printf("%d\n",(f[p][0][0]+f[p][0][1])%10000);
    }
    return 0;
}
