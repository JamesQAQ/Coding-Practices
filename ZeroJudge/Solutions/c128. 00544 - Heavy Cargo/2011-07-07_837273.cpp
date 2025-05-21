#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

struct Node {int to,w;} temp;
int main()
{
    int n,m,a,b,num,start,end,d[200],cases=0;
    bool use[200];
    string sa,sb,ss,se;
    vector <Node> path[200];
    map <string,int> Map;
    while (scanf("%d %d",&n,&m)){
        if (n==0&&m==0)
            break;
        Map.clear();
        num=1;
        for (int i=0;i<n;i++)
            path[i].clear(),d[i]=0,use[i]=false;
        for (int i=0;i<m;i++){
            cin>>sa>>sb;
            scanf("%d",&temp.w);
            if (Map[sa]==0)
                Map[sa]=num++;
            a=Map[sa]-1;
            if (Map[sb]==0)
                Map[sb]=num++;
            b=Map[sb]-1;
            temp.to=b;
            path[a].push_back(temp);
            temp.to=a;
            path[b].push_back(temp);            
        }
        cin>>ss>>se;
        start=Map[ss]-1,end=Map[se]-1;
        d[start]=10001;
        for (int i=0;i<n;i++){
            int maxxat=-1;
            for (int j=0;j<n;j++)
                if (!use[j]&&(maxxat==-1||d[j]>d[maxxat]))
                    maxxat=j;
            if (maxxat==-1||maxxat==end)
                break;
            use[maxxat]=true;
            int p=path[maxxat].size();
            for (int j=0;j<p;j++){
                int to=path[maxxat][j].to;
                if (!use[to])
                    d[to]=max(d[to],min(d[maxxat],path[maxxat][j].w));
            }
        }
        printf("Scenario #%d\n%d tons\n",++cases,d[end]);
    }
    return 0;
}
