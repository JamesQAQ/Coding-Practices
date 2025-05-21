#include <iostream>
using namespace std;

int main()
{
    int v,a,b,i=0,temp;
    bool s[32]={0};
    while (cin>>v>>a>>b)
    {
        if (v<0)
            temp=-(v+1);
        else
            temp=v;
        while (temp>=1)
        {
            s[i]=temp%2;
            temp=(temp%2==1)?(temp-1)/2:temp/2;
            i++;
        }
        i=0;
        if (v<0)
            for (int ii=31;ii>=0;ii--)
                s[ii]=(s[ii]==0)?1:0;
        s[a]=b;
        for (int ii=31;ii>=0;ii--)
        {
            cout<<s[ii];
            s[ii]=0;
        }
        cout<<endl;
    }
    //system("pause");
    return 0;
}
