#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

struct Node {int t,T;} p[60];
int m,car[60];
bool use[60];
bool cmp(Node i,Node j){
    if (i.t<j.t)
        return true;
    if (i.t>j.t)
        return false;
    return i.T<j.T;
}
bool dfs(int x,int n){
    if (x==m)
        return true;
    int i=x;
            for (int j=0;j<n;j++)
                if (p[i].t+30>car[j]){
                    int tmp=car[j];
                    car[j]=max(tmp,p[i].t)+p[i].T;
                    if (dfs(x+1,n))
                        return true;
                    car[j]=tmp;
            }
    return false;
}
int main()
{
    while (scanf("%d",&m)==1){
        for (int i=0;i<m;i++)
            scanf("%d %d",&p[i].t,&p[i].T);
        std::stable_sort(p,p+m,cmp);
        int l=1,r=m,mid;
        while (l<=r){
            mid=(l+r)/2;
            for (int i=0;i<mid;i++)
                car[i]=0;
            for (int i=0;i<m;i++)
                use[i]=false;
            if (dfs(0,mid))
                r=mid-1;
            else
                l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;    
}
