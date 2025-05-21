#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,t[100000],ans;
    while (scanf("%d",&n)==1){
        ans=0;
        for (int i=0;i<n;i++)
            scanf("%d",&t[i]);
        stable_sort(t,t+n);
        int d;
        for (d=n-1;d>=3;d-=2)
            ans+=min(2*t[0]+t[d]+t[d-1],2*t[1]+t[0]+t[d]);
        if (d==2) ans+=t[0]+t[1]+t[2];
        else if (d==1) ans+=t[1];
        else if (d==0) ans+=t[0];
        printf("%d\n",ans);
    }
    return 0;
}
