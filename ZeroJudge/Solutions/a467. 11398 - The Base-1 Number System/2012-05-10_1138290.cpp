#include <cstdio>

int main()
{
    char S[100000];
    while (gets(S)){
        if (S[0]=='~')
            break;
        int sum=0,s,x=0;
        for (int i=0;S[i];i++){
            if (S[i]==' '){
                //printf("sum %d\n",sum);
                if (sum==1)
                    s=1;
                else if (sum==2)
                    s=0;
                else{
                    for (int i=0;i<sum-2;i++)
                        x=(x<<1)+s;
                }
                //printf("x %d\n",x);
                sum=0;
            }
            else
                sum++;
        }
        printf("%d\n",x);
    }
}
