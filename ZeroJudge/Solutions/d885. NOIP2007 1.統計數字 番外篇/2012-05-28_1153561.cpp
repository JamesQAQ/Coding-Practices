#include <cstdio>
#include <vector>

int a[5000000];
int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
int mod=65536;
std::vector <int> box[65536];
void radix_sort(int a[],int n){
    for (int i=0;i<n;i++)
        box[a[i]%mod].push_back(a[i]);
    int num=0;
    for (int i=0;i<mod;i++){
        int p=box[i].size();
        for (int j=0;j<p;j++)
            a[num++]=box[i][j];
        box[i].clear();
    }
    for (int i=0;i<n;i++)
        box[a[i]/mod].push_back(a[i]);
    num=0;
    for (int i=0;i<mod;i++){
        int p=box[i].size();
        for (int j=0;j<p;j++)
            a[num++]=box[i][j];
        box[i].clear();
    }
}
int main()
{
    int n;
    n=input();
    for (int i=0;i<n;i++)
        a[i]=input();
    radix_sort(a,n);
    int f=a[0],cnt=1;
    for (int i=1;i<n;i++){
        if (f!=a[i]){
            printf("%d %d\n",f,cnt);
            f=a[i],cnt=0;
        }
        cnt++;
    }
    printf("%d %d\n",f,cnt);
    //while (1);
}
