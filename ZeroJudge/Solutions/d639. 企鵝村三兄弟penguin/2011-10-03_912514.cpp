#include <cstdio>
#include <iostream>

struct Node {int a[3];} a[2],*pre,*now;
int main()
{
    pre=&a[0],now=&a[1];
    int mod=10007,martix[31][3][3]={},n;
    martix[0][0][1]=martix[0][1][2]=martix[0][2][0]=martix[0][2][1]=martix[0][2][2]=1;
    for (int i=1;i<31;i++)
        for (int j=0;j<3;j++)
            for (int k=0;k<3;k++){
                int temp=0;
                for (int l=0;l<3;l++)
                    temp+=martix[i-1][j][l]*martix[i-1][l][k];
                martix[i][j][k]=temp%mod;
            }
    while (scanf("%d",&n)==1){
        n--;
        for (int i=0;i<3;i++)
            now->a[i]=1;
        for (int i=1<<30,j=30;j>=0;j--,i>>=1)
            if (i&n){
                std::swap(now,pre);
                for (int k=0;k<3;k++){
                    int temp=0;
                    for (int l=0;l<3;l++)
                        temp+=martix[j][k][l]*pre->a[l];
                    now->a[k]=temp%mod;
                }
            }
        printf("%d\n",now->a[0]);
    }
    return 0;
}
