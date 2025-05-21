#include <cstdio>
#include <algorithm>

int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
struct Node {int x,y;} door[50000];
bool cmp(int i,int j){
    if (door[i].x<door[j].x)
        return true;
    if (door[i].x>door[j].x)
        return false;
    return door[i].y>door[j].y;
}
int main()
{
    int cases,n,k,num,stack[50000],t[50000],top,l,r,mid;
    cases=input();
    while (cases--){
        num=0;
        n=input(),k=input();
        for (int i=0;i<k;i++)
            door[i].x=input(),t[i]=i;
        for (int i=0;i<k;i++)
            door[i].y=input();
        for (int i=0;i<k;i++)
            if (door[i].x!=n&&door[i].y!=n)
                door[num++]=door[i];
        std::stable_sort(t,t+num,cmp);
        top=0;
        for (int i=0;i<num;i++){
            int v=door[t[i]].y;
            if (top==0||v>stack[top-1])
                stack[top++]=v;
            else{
                l=0,r=top-1;
                while (l<=r){
                    mid=(l+r)/2;
                    if (stack[mid]>v)
                        r=mid-1;
                    else if (stack[mid]<v)
                        l=mid+1;
                    else{
                        l=mid;
                        break;
                    }
                }
                stack[l]=v;
            }
        }
        printf("%d\n",2*n-top-2);
    }
}
