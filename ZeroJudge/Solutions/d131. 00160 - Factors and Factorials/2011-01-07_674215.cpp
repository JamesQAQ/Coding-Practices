#include <iostream>
using namespace std;

int main()
{
    int p[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97},n;
    while (cin>>n)
    {
        if (n==0)
            break;
        printf("%3d! =",n);
        for (int i=0;i<25;i++)
        {
            if (p[i]>n)
                break;
            if (i==15)
                cout<<"\n      ";
            int sum=0,nn=n;
            while (nn!=0)
            {
                nn/=p[i];
                sum+=nn;
            }
            printf("%3d",sum);
        }
        puts("");
    }
    return 0;
}
