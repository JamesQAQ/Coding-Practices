#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

int main()
{
    int t=0,d,di[4];
    double dii[4]={1,sqrt(2)/2,1,sqrt(2)/2},ans[2];
    string s,temp;
    cout.setf(ios::fixed);
    cout.precision(3);
    while (cin>>s)
    {
        if (s=="END")
            break;
        memset(di,0,sizeof(di));
        s.erase(s.length()-1,1);
        int len=s.length(),p;
        while (len>0)
        {
            p=s.find(",");
            if (p==-1)
            {
                temp=s;
                len=0;
            }
            else
            {
                temp=s.substr(0,p);
                s.erase(0,p+1);
            }
            stringstream ss(temp);
            ss>>d>>temp;
            if (temp=="N")
                di[2]+=d;
            else if (temp=="E")
                di[0]+=d;
            else if (temp=="S")
                di[2]-=d;
            else if (temp=="W")
                di[0]-=d;
            else if (temp=="NE")
            {
                di[1]+=d;
                di[3]+=d;
            }
            else if (temp=="SE")
            {
                di[1]+=d;
                di[3]-=d;
            }
            else if (temp=="SW")
            {
                di[1]-=d;
                di[3]-=d;
            }
            else
            {
                di[1]-=d;
                di[3]+=d;
            }
            len-=p+1;
        }
        ans[0]=di[0]*dii[0]+di[1]*dii[1];
        ans[1]=di[2]*dii[2]+di[3]*dii[3];
        cout<<"Map #"<<++t<<endl;
        cout<<"The treasure is located at ("<<ans[0]<<","<<ans[1]<<")."<<endl;
        cout<<"The distance to the treasure is "<<sqrt(ans[0]*ans[0]+ans[1]*ans[1])<<"."<<endl<<endl;
    }
    return 0;
}
