#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    //freopen("in_2.txt","r",stdin);
    int n,a,b,c;
    short map[20][20],map2[20][20];
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=1;i<20;i++)  
            for (int j=1;j<20;j++)
                map[i][j]=2;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a);
            scanf("%d",&b);
            scanf("%d",&c);
            map[a][b]=c;
            if (c==0)
                map[a][b]=3;
        }
        int ans=0;
        scanf("%d",&n);
        for (int i=1;i<20;i++)  
            for (int j=1;j<20;j++)
                map2[i][j]=2;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a);
            scanf("%d",&b);
            scanf("%d",&c);
            map2[a][b]=c;
            if (c==0)
                map2[a][b]=3;
        }
        for (int i=1;i<20;i++)
            for (int j=1;j<20;j++)
                ans+=abs(map[i][j]-map2[i][j]);
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}
