#include <cstdio>

double r;
int ok(int x,int y){
    int dis=x*x+y*y;
    return r>=dis;
}
int main()
{
    int n;
    while (scanf("%d",&n)==1){
        int all=0,cover=0;
        r=(2*n-1)/2.0;
        r*=r;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++){
                int cnt=ok(i,j)+ok(i+1,j)+ok(i,j+1)+ok(i+1,j+1);
                if (cnt) cover++;
                if (cnt==4) all++;
            }
        printf("In the case n = %d, %d cells contain segments of the circle.\n",n,4*cover-4*all);
        printf("There are %d cells completely contained in the circle.\n",all*4);
    }
}
