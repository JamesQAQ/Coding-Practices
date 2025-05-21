#include <iostream>
using namespace std;

int main()
{
    int n;
    double x1,y1,x3,y3,x2,y2,max,mix,may,miy;
    while (cin>>n)
    {
        for (int i=0;i<n;i++)
        {
            cin>>x1>>y1>>x3>>y3>>x2>>y2;
            max=(x1>x3)?x1:x3;
            mix=(x1<=x3)?x1:x3;
            may=(y1>y3)?y1:y3;
            miy=(y1<=y3)?y1:y3;
            if (((x2>=mix)&&(x2<=max))&&((y2>=miy)&&(y2<=may)))
            {
                if ((x3-x2)/(y3-y2)==(x3-x1)/(y3-y1))
                    cout<<"該死的東西!竟敢想讓我死！"<<endl;
                else if ((y3-y2)/(x3-x2)==(y3-y1)/(x3-x1))
                    cout<<"該死的東西!竟敢想讓我死！"<<endl;
                else if ((x1==x2)&&(x2==x3)&&(y1==y2)&&(y2==y3))
                    cout<<"該死的東西!竟敢想讓我死！"<<endl;
                else
                    cout<<"父親大人!母親大人!我快到了！"<<endl;
            }
            else
                cout<<"父親大人!母親大人!我快到了！"<<endl;
        }
    } 
    //system("pause");
    return 0;
}
