#include <cstdio>

int main()
{
    int l,v[20001]={};
    for (int i=0,j=1;i+j<=20000;j++){
        v[i+1]=1;
        if (i+j+1<=20000)
            v[i+j+1]=1;
        i+=j+j;
    }
    for (int j=1;j<=20000;j++)
        v[j]+=v[j-1];
    while (scanf("%d",&l)==1)
        printf("%d\n",v[l]);
}
