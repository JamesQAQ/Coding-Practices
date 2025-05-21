#include <cstdio>

int main()
{
    int n,a[4],b[4];
    bool usea[4],useb[4];
    while (scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3])==4){
        scanf("%d",&n);
        while (n--){
            int A=0,B=0;
            for (int i=0;i<4;i++)
                scanf("%d",&b[i]),usea[i]=useb[i]=false;
            for (int i=0;i<4;i++)
                if (a[i]==b[i])
                    A++,usea[i]=useb[i]=true;
            for (int i=0;i<4;i++)
                if (!useb[i]){
                    for (int j=0;j<4;j++)
                        if (!usea[j]&&b[i]==a[j]){
                            B++,usea[j]=true;
                            break;
                        }
                }
            printf("%dA%dB\n",A,B);
        }
    }    
}
