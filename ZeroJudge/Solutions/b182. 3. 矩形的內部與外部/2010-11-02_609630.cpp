#include <iostream>
using namespace std;

int main()
{
   long long n,m,d[30][4],area[30],x,y;
   while (cin>>n>>m)
   {
      for (long long i=0;i<n;i++)
      {
         long long x1,y1,x2,y2;
         cin>>x1>>y1>>x2>>y2;
         d[i][2]=max(x1,x2);
         d[i][0]=min(x1,x2);
         d[i][3]=max(y1,y2);
         d[i][1]=min(y1,y2);
         area[i]=(d[i][2]-d[i][0])*(d[i][3]-d[i][1]);
      }
      for (long long i=0;i<m;i++)
      {
         long long sum=0;
         cin>>x>>y;
         for (long long j=0;j<n;j++)
            if ((x<=d[j][2]&&d[j][0]<=x)&&(y<=d[j][3]&&d[j][1]<=y))
               sum+=area[j];
         cout<<sum<<endl;
      }
   }
   return 0;
}
