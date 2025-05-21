#include <cstdio>

int stack[3][15],num[3];
void hanoi(int n,int a,int b,int c){
    if (n==1){
        stack[c][num[c]++]=stack[a][num[a]-1];
        num[a]--;
        printf("Move ring %d from %c to %c\n",stack[a][num[a]],a+'A',c+'A');
        return;
    }
    hanoi(n-1,a,c,b);
    stack[c][num[c]++]=stack[a][num[a]-1];
    num[a]--;
    printf("Move ring %d from %c to %c\n",stack[a][num[a]],a+'A',c+'A');
    hanoi(n-1,b,a,c);
}
int main()
{
    int n;
    while (scanf("%d",&n)==1){
        num[1]=num[2]=0;
        num[0]=n;
        for (int i=0;i<n;i++)
            stack[0][i]=n-i;
        hanoi(n,0,1,2);
        puts("");
    }
    return 0;
}
