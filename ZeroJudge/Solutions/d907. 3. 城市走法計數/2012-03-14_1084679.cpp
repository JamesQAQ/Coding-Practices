#include <cstdio>

int n,tmp[10][10],boss[10],sum[10];
struct Martix{
    int a[10][10];
    void operator *=(Martix b){
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++){
                int temp=0;
                for (int k=0;k<n;k++)
                    temp+=a[i][k]*b.a[k][j];
                tmp[i][j]=temp;
            }
        for (int i=0;i<n;i++)   
            for (int j=0;j<n;j++)
                a[i][j]=tmp[i][j];
    }
} ans,map;
int find(int x){
    return (x==boss[x])?x:(boss[x]=find(boss[x]));
}
int main()
{
    char s[11];
    int st,ed,step;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        boss[i]=i,sum[i]=1;
    for (int i=0;i<n;i++){
        scanf("%s",s);
        for (int j=0;j<n;j++){
            map.a[i][j]=s[j]-'0';
            if (map.a[i][j]){
                int bossa=find(i),bossb=find(j);
                if (bossa!=bossb){
                    if (bossa>bossb)
                        bossa^=bossb^=bossa^=bossb;
                    sum[bossa]+=sum[bossb];
                    sum[bossb]=0;
                    boss[bossb]=bossa;
                }
            }
        }
    }
    scanf("%d %d %d",&st,&ed,&step);
    st--,ed--;
    ans=map;
    for (int i=0;i<step;i++)
        ans*=map;
    printf("%d\n",ans.a[st][ed]);
    if (sum[0]==n)
        puts("0\n0");
    else{
        puts("1");
        for (int i=1;i<n;i++)
            if (find(i)!=0){
                printf("%d\n",i+1);
                break;
            }
    }
}
