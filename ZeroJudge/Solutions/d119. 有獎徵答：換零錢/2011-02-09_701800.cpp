#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string s;
    int coin[10]={1,5,10,20,50,100,200,500,1000,2000};
    unsigned long long ways[50001]={};
    ways[0]=1;
    for(int i=0;i<10;i++)
        for(int j=coin[i];j<=50000;j++)
            ways[j]+=ways[j-coin[i]];
    int n;
    while(getline(cin,s))
    {
        stringstream ss(s);
        int sum=0,temp;
        while (ss>>temp)
            sum+=temp;
        if (sum==0)
            break;
        cout<<ways[sum]-1<<endl;
    }
    return 0;
}
