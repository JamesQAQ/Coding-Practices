#include <cstdio>

int main()
{
    int n;
    while (scanf("%d",&n),n){
        int i=1;
        while (i<n){
            for (int j=0;i<n&&j<6;i++,j++){
                if (i-1)
                    printf(" ");
                printf("%d",i);
            }
            i++;
        }
        puts("");
    }
    return 0;
}
