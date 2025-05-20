#include <iostream>
#include <algorithm>
using namespace std;

string name[1000],kind[1000];
int a[1000][2],n;
double b[1000];
bool cmp(int i,int j)
{
    if (kind[i]>kind[j])
        return 1;
    if (kind[i]<kind[j])
        return 0;
    if (a[i][0]>a[j][0])
        return 1;
    if (a[i][0]<a[j][0])
        return 0;
    if (a[i][1]>a[j][1])
        return (kind[i]=="B")?1:0;
    if (a[i][1]<a[j][1])
        return (kind[i]=="B")?0:1;
    if (b[i]>b[j])
        return (kind[i]=="B")?1:0;
    if (b[i]<b[j])
        return (kind[i]=="B")?0:1;
}
int main()
{
    int cases,t[1000];
    while (cin>>cases)
    {
        for (int k=0;k<cases;k++)
        {
            if (k)
                cout<<"====="<<endl;
            cin>>n;
            for (int i=0;i<n;i++)
            {
                cin>>kind[i]>>name[i]>>a[i][0]>>a[i][1]>>b[i];
                t[i]=i;
            }
            stable_sort(t,t+n,cmp);
            for (int i=0;i<n;i++)
                cout<<kind[t[i]]<<" "<<name[t[i]]<<endl;
        }
    }
    return 0;
}
