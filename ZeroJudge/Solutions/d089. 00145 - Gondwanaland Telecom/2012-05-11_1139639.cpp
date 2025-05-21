#include <cstdio>

inline int get(){
    int h,m;
    scanf("%d %d",&h,&m);
    return h*60+m;
}
int main()
{
    char c,s[10];
    double v[5][3]={{0.1,0.06,0.02},{0.25,0.15,0.05},{0.53,0.33,0.13},{0.87,0.47,0.17},{1.44,0.8,0.3}};
    int st,ed,tim[8]={0,8,18,22,32,42,46,56},tag[7]={2,0,1,2,0,1,2};
    for (int i=0;i<7;i++)
        tim[i]*=60;
    //int cases=0;
    while (scanf(" %c",&c),(c!='#')){
        //cases++;
        scanf("%s",s);
        st=get(),ed=get();
        if (st>ed)
            ed+=24*60;
        //if (cases==80)
        //    printf("%d %d\n",st,ed);
        int sum[3]={},at=0;
        for (int i=0;i<7;i++){
            if (tim[i]>=ed)
                break;
            if (st<=tim[i]&&tim[i+1]<=ed)
                sum[tag[i]]+=tim[i+1]-tim[i];
            else if (tim[i]<=st&&ed<=tim[i+1])
                sum[tag[i]]+=ed-st;
            else if (st<tim[i]&&tim[i]<=ed&&ed<=tim[i+1])
                sum[tag[i]]+=ed-tim[i];
            else if (tim[i]<=st&&st<=tim[i+1]&&tim[i+1]<ed)
                sum[tag[i]]+=tim[i+1]-st;
            
            //printf("tim %d\n",tim[i]);
            //printf("  %s%6d%6d%6d  %c\n",s,sum[0],sum[1],sum[2],c);
        }
        printf("  %s%6d%6d%6d  %c%8.2lf\n",s,sum[0],sum[1],sum[2],c,(double)sum[0]*v[c-'A'][0]+(double)sum[1]*v[c-'A'][1]+(double)sum[2]*v[c-'A'][2]);
    }
}
