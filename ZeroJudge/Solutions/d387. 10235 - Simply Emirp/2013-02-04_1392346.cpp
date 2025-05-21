#include <cstdio>
 
bool p[1000001]={};
int change(int x){
    int sum=0;
    while (x!=0){
        sum=sum*10+x%10;
        x/=10;
    }
    return sum;
}
void judge(int x){
    if (!p[x])
        printf("%d is not prime.\n",x);
    else{
        int xx=change(x);
        if (p[xx]&&x!=xx)
            printf("%d is emirp.\n",x);
        else
            printf("%d is prime.\n",x);
    }
}
int main()
{
    p[2]=true;
    for (int i=3;i<1000001;i+=2)
        p[i]=true;
    for (int i=3;i<1000;i+=2)
        if (p[i])
            for (int j=i*i;j<1000001;j+=2*i)
                p[j]=false;
    int n;
    while (scanf("%d",&n)==1)
        judge(n);
    return 0;
}
