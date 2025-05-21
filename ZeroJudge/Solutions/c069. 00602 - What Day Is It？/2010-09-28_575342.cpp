#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char date[7][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    char month[12][10]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int m,d,y,cdate;
    while (scanf("%d %d %d",&m,&d,&y))
    {
        if (m==0)
            break;
        day[2]=28;
        if (m>12)
        {
            printf("%d/%d/%d is an invalid date.\n",m,d,y);
            continue;
        }
        if (y<1752||(y==1752&&(m<9||(m==9&&d<=2))))
        {
            if (y%4==0)
                day[2]++;
        }
        else
        {
            if (y%400==0)
                day[2]++;
            else if (y%4==0&&y%100!=0)
                day[2]++;
        }
        if (d>day[m])
        {
            printf("%d/%d/%d is an invalid date.\n",m,d,y);
            continue;
        }
        if (y<1752||(y==1752&&(m<9||(m==9&&d<=2))))
        {
            cdate=6;
            cdate+=y-1+(y-1)/4;
            cdate%=7;
            for (int i=1;i<m;i++)
                cdate+=day[i];
            cdate+=d-1;
            cdate%=7;
            printf("%s %d, %d is a %s\n",month[m-1],d,y,date[cdate]);
        }
        else if (m==9&&y==1752&&d>=3&&d<=13)
        {
            printf("%d/%d/%d is an invalid date.\n",m,d,y);
            continue;
        }
        else
        {
            cdate=6;
            cdate+=y-1752+(y-1749)/4-(y-1701)/100+(y-1601)/400;
            cdate%=7;
            for (int i=1;i<m;i++)
                cdate+=day[i];
            cdate+=d-1;
            cdate%=7;
            printf("%s %d, %d is a %s\n",month[m-1],d,y,date[cdate]);
        }
    }
    return 0;
}
