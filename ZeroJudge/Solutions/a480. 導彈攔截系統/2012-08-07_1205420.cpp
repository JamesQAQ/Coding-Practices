#include <cstdio>
#include <algorithm>

int ta[1000000],tb[1000000],da[1000000],db[1000000];
bool cover[1000000];
bool cmpa(int i,int j){
    return da[i]<da[j];
}
bool cmpb(int i,int j){
    return db[i]>db[j];
}
int dis(int x1,int y1,int x2,int y2){
    int x=x1-x2,y=y1-y2;
    return x*x+y*y;
}
int input(){
    char c=getchar();
    while (c!='-'&&(c>'9'||c<'0')) c=getchar();
    bool negative=(c=='-');
    int x=(negative)?0:c-48;
    c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return (negative)?-x:x;
}
int main()
{
    int ax,ay,bx,by,x,y;
    ax=input(),ay=input(),bx=input(),by=input();
    //scanf("%d %d %d %d",&ax,&ay,&bx,&by);
    int n;
    n=input();
    for (int i=0;i<n;i++){
        x=input(),y=input();
        ta[i]=i,tb[i]=i;
        da[i]=dis(ax,ay,x,y);
        //printf("%d\n",da[i]);
        db[i]=dis(bx,by,x,y);
        //printf("da %d db %d\n",da[i],db[i]);
    }
    std::stable_sort(ta,ta+n,cmpa);
    std::stable_sort(tb,tb+n,cmpb);
    int at=0,ans=db[tb[0]];
    for (int i=0;i<n;i++){
        cover[ta[i]]=true;
        while (at<n&&cover[tb[at]])
            at++;
        int v=da[ta[i]]+((at==n)?0:db[tb[at]]);
        if (v<ans)
            ans=v;
    }
    printf("%d\n",ans);
    //while (1);
}
