#include <iostream>
using namespace std;

int main()
{
    int n,x1,y1,x2,y2,x3,y3;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        scanf("%d,%d %d,%d %d,%d",&x1,&y1,&x2,&y2,&x3,&y3);
        if ((x1-x2)*(y2-y3)==(x2-x3)*(y1-y2))
            cout<<"collinear"<<endl;
        else
            cout<<"not collinear"<<endl;
    }
    return 0;
}
