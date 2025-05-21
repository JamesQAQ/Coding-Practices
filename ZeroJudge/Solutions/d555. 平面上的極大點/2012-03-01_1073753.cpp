#include <cstdio>

int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
bool need[100001];
int X[100001],ansx[500000],ansy[500000],top;
int main()
{
    int n,x,y,maxx,t=0;
    while (scanf("%d",&n)==1){
        maxx=top=0;
        X[0]=0,need[0]=false;
        for (int i=0;i<n;i++){
            x=input(),y=input();
            if (y>maxx){
                for (int i=maxx+1;i<=y;i++)
                    need[i]=false,X[i]=0;
                maxx=y;
            }
            need[y]=true;
            if (x>X[y]) X[y]=x;
        }
        int dx=-1;
        for (int i=maxx;i>=0;i--)
            if (need[i])
                if (X[i]>dx){
                    dx=X[i];
                    ansx[top]=dx,ansy[top]=i;
                    top++;
                }
        printf("Case %d:\nDominate Point: %d\n",++t,top);
        for (int i=0;i<top;i++)
            printf("(%d,%d)\n",ansx[i],ansy[i]);
    }
}
