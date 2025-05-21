#include <cstdio>

int sum[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool round(int y){
    return (y%400==0||(y%4==0&&y%100!=0));
}
int cnt(int y,int m,int d){
    int _y=y-1,day=_y*365+_y/400-_y/100+_y/4;
    day+=sum[m-1]+d;
    if (round(y)&&m>2)
        day++;
    return day;
}
int main()
{
    for (int i=1;i<=12;i++)
        sum[i]+=sum[i-1];
    int y,m,d,day1,day2;
    while (scanf("%d %d %d",&y,&m,&d)==3){
        day1=cnt(y,m,d);
        scanf("%d %d %d",&y,&m,&d);   
        day2=cnt(y,m,d);
        printf("%d\n",((day1>day2)?day1-day2:day2-day1));
    }
    return 0;
}
