#include <iostream>
using namespace std;
struct Node {int d,m,y;} a,b;
int main()
{
    int n,t=0;
    while (cin>>n)
        while (n-->0)
        {
            scanf("%d/%d/%d",&a.d,&a.m,&a.y);
            scanf("%d/%d/%d",&b.d,&b.m,&b.y);
            int ans=a.y-b.y;
            if (a.m*100+a.d<b.m*100+b.d)
                ans--;
            printf("Case #%d: ",++t);
            if (ans<0)
                puts("Invalid birth date");
            else if (ans>130)
                puts("Check birth date");
            else
                cout<<ans<<endl;
        }
    return 0;
}
