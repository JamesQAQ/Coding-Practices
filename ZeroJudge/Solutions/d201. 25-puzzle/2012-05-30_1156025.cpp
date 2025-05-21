#include <cstdio>

bool ok(int a[]){
    for (int i=0;i<25;i++)
        if (a[i]!=i)
            return false;
    return true;
}
int main()
{
    int a[25];
    int cases;
    scanf("%d",&cases);
    while (cases--){
        for (int i=0;i<25;i++)
            scanf("%d",&a[i]);
        puts((!ok(a))?"I must cheat!!!":"0");
    }
}
