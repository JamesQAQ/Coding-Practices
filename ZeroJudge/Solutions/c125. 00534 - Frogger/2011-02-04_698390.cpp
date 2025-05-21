#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(3);
    int x[200],y[200],n,t=0;
    double d[200],path[200][200];
    bool use[200];
    while (cin>>n)
    {
        if (n==0)
            break;
        for (int i=0;i<n;i++)
        {
            cin>>x[i]>>y[i];
            use[i]=0;
        }
        use[0]=1;
        for (int i=0;i<n-1;i++)
            for (int j=i+1;j<n;j++)
            {
                int dx=x[i]-x[j],dy=y[i]-y[j];
                path[i][j]=path[j][i]=sqrt(dx*dx+dy*dy);
            }
        for (int i=1;i<n;i++)
            d[i]=path[0][i];
        for (int k=1;k<n;k++)
        {
            int at=-1;
            for (int i=1;i<n;i++)
                if (!use[i]&&(at==-1||d[i]<d[at]))
                    at=i;
            use[at]=1;
            if (at==1)
                break;
            for (int i=1;i<n;i++)
                if (!use[i])
                    d[i]=min(d[i],max(d[at],path[at][i]));
        }
        cout<<"Scenario #"<<++t<<endl;
        cout<<"Frog Distance = "<<d[1]<<endl<<endl;
    }
    return 0;
}
