#include <cstdio>

int input(){
    char c=getchar();
    while (c==' '||c=='\n') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;    
}
int main()
{
    int n,m,a[100][100],X[100],Y[100],all;
    while (scanf("%d %d",&n,&m)==2){
        all=0;
        for (int i=0;i<n;i++)
            X[i]=0;
        for (int i=0;i<m;i++)
            Y[i]=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++){
                a[i][j]=input();
                all+=a[i][j];
                X[i]+=a[i][j];
                Y[j]+=a[i][j];
            }
        int up=0,down=all,sum=0,tmp,ans=2147483647,ansx,ansy;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                sum+=(i+j)*a[i][j];
        for (int i=0;i<n;i++){
            tmp=sum;
            int left=0,righ=all;
            for (int j=0;j<m;j++){
                if (tmp<ans){
                    ans=tmp;
                    ansx=i,ansy=j;
                }
                left+=Y[j],righ-=Y[j];
                tmp+=left-righ;
            }
            up+=X[i],down-=X[i];
            sum+=up-down;
        }
        printf("%d %d\n",ansx+1,ansy+1);
    }
}
