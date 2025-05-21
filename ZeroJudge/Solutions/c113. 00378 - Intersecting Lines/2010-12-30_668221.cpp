#include <iostream>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);
    double xx[4],yy[4],delta,m[2],c[2];
    int n,x[4],y[4];
    while (cin>>n)
    {
        cout<<"INTERSECTING LINES OUTPUT"<<endl;
        while (n-->0)
        {
            for (int i=0;i<4;i++)
                cin>>x[i]>>y[i];
            if ((x[0]-x[1])*(y[2]-y[3])==(x[2]-x[3])*(y[0]-y[1]))
            {
                if ((x[0]-x[1])*(y[0]-y[2])==(x[0]-x[2])*(y[0]-y[1]))
                    cout<<"LINE"<<endl;
                else
                    cout<<"NONE"<<endl;
            }
            else
            {
                cout<<"POINT ";
                for (int i=0;i<4;i++)
                {
                    xx[i]=(double)x[i];
                    yy[i]=(double)y[i];
                }
                if (x[0]==x[1])
                    cout<<xx[0]<<" "<<(yy[2]-yy[3])/(xx[2]-xx[3])*(xx[0]-xx[2])+yy[2]<<endl;
                else if (x[2]==x[3])
                    cout<<xx[2]<<" "<<(yy[0]-yy[1])/(xx[0]-xx[1])*(xx[2]-xx[0])+yy[0]<<endl;
                else
                {
                    m[0]=(yy[0]-yy[1])/(xx[0]-xx[1]);
                    m[1]=(yy[2]-yy[3])/(xx[2]-xx[3]);
                    delta=m[1]-m[0];
                    c[0]=m[0]*xx[0]-yy[0];
                    c[1]=m[1]*xx[2]-yy[2];
                    cout<<(c[1]-c[0])/delta<<" "<<(m[0]*c[1]-m[1]*c[0])/delta<<endl;
                }
            }
        }
        cout<<"END OF OUTPUT"<<endl;
    }
    return 0;
}
