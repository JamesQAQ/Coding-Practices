#include <cstdio>

struct Node{
    int a[5][5];
    int cost(Node b){
        int sum=0;
        for (int i=0;i<5;i++)
            for (int j=0;j<5;j++){
                int I=a[i][j],J=b.a[i][j];
                if (I==1&&J==1)
                    sum+=1;
                else if (I==8&&J==1)
                    sum+=2;
                else if (I==8&&J==8)
                    sum+=5;
                else
                    sum+=7;
            }
        return sum;
    }
    void get(){
        for (int i=0;i<5;i++)
            for (int j=0;j<5;j++)
                scanf("%d",&a[i][j]);
    }
} f,now;
int main()
{
    int n;
    scanf("%d",&n);
    f.get();
    for (int i=1;i<n;i++){
        now.get();
        printf("%d\n",f.cost(now));
        f=now;
    }
}
