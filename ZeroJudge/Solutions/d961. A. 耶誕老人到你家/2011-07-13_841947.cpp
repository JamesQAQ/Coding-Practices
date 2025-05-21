#include <cstdio>
#include <algorithm>

int main()
{
    int cases,n,m,gift[50000],box[50000];
    scanf("%d",&cases);
    while (cases--){
        scanf("%d %d",&n,&m);
        for (int i=0;i<n;i++)
            scanf("%d",&gift[i]);
        for (int i=0;i<m;i++)
            scanf("%d",&box[i]);
        std::stable_sort(gift,gift+n);
        std::stable_sort(box,box+m);
        int at=0,ans=0;
        for (int i=0;i<n;i++){
            while (at<m&&gift[i]>box[at])
                at++;
            if (at<m&&gift[i]<=box[at])
                ans++,at++;
            
        }
        (ans==0)?puts("Santa Claus wishes you get AC in the next submission."):printf("%d\n",ans);
    }
    return 0;
}
