#include <cstdio>
#include <queue>
#include <algorithm>

int n;
short use[3001][3001]={};
struct Node {int a[3];} temp,b;
int main()
{
    int a[3],sum;
    short t=0;
    while (scanf("%d",&n),n){
        t++;
        for (int i=0;i<3;i++)
            scanf("%d",&a[i]);
        for (int i=0;i<3;i++)
            scanf("%d",&b.a[i]);
        sum=b.a[0]+b.a[1]+b.a[2];
        if (a[0]+a[1]+a[2]!=sum)
            puts("No");
        else{
            std::queue <Node> Q;
            std::sort(b.a,b.a+3);
            std::sort(a,a+3);
            temp=b;
            Q.push(temp);
            use[b.a[0]][b.a[1]]=t;
            bool ok=false;
            while (!Q.empty()){
                b=Q.front();
                Q.pop();
                if (b.a[0]==a[0]&&b.a[1]==a[1]){
                    ok=true;
                    break;
                }
                for (int i=0;i<3;i++)
                    for (int j=0;j<3;j++)
                        if (i!=j){
                            temp=b;
                            int x=b.a[i]+2*b.a[j]+1,y=2*b.a[i]+b.a[j]-1;
                            if (x%3==0&&y%3==0){
                                temp.a[i]=x/3,temp.a[j]=y/3;
                                std::sort(temp.a,temp.a+3);
                                if (temp.a[0]>=0&&temp.a[2]<=n&&use[temp.a[0]][temp.a[1]]!=t){
                                    use[temp.a[0]][temp.a[1]]=t;
                                    Q.push(temp);
                                }                                
                            }
                        }
            }
            puts((ok)?"Yes":"No");
        }
    }
    return 0;
}
