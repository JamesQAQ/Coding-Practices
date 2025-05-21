#include <cstdio>
#include <vector>

std::vector <int> path[200];
int n,m,a,b,queue[200],top,color[200];
int input(){
	char c=getchar();
	while (c==' '||c=='\n')
		c=getchar();
	int x=c-48;
	c=getchar();
	while (c!=' '&&c!='\n'){
		x=x*10+c-48;
		c=getchar();
	}
	return x;
}
int main()
{
    while (n=input()){
		if (n==0)
			break;
        for (int i=0;i<n;i++)
            path[i].clear(),color[i]=0;
        m=input();
        for (int i=0;i<m;i++){
            a=input();
            b=input();
			path[a].push_back(b),path[b].push_back(a);
		}
        color[0]=1;
        queue[0]=0;
        top=1;
        bool ok=true;
        for (int i=0;i<top;i++){
            int x=queue[i],other=(color[x]==1)?2:1,p=path[x].size();
            for (int i=0;i<p;i++){
                int to=path[x][i];
                if (color[to]==0){
                    color[to]=other;
                    queue[top++]=to;
                }
                else if (color[to]!=other){
                    ok=false;
                    break;
                }
            }
            if (!ok)
                break;
        }
        (ok)?puts("BICOLORABLE."):puts("NOT BICOLORABLE.");
    }
    return 0;
}
