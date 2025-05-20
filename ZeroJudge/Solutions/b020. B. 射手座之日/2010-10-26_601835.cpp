#include <iostream>
#include <deque>
#include <algorithm>
#include <bitset>
using namespace std;

bool finish;
int n,sum,end[3],temp[3];
bitset <3001> use[3001]; 
struct Node {int x,y,z;};
deque <Node> Q;
Node a;
bool test(int aa,int bb,int cc)
{
    temp[0]=2*aa-bb+1;
    temp[1]=2*bb-aa-1;
    temp[2]=cc;
    stable_sort(temp,temp+3);
    int x=temp[0],y=temp[1],z=temp[2];
    if (x>=end[0]&&z<=end[2])
        if (!use[x][z])
        {
            use[x][z]=1;
            a.x=x;
            a.y=y;
            a.z=z;
            return 1;
        }
    return 0;
}
int main()
{
    while (cin>>n>>temp[0]>>temp[1]>>temp[2]>>end[0]>>end[1]>>end[2])
    {
        if (n==0&&temp[0]==0&&temp[1]==0&&temp[2]==0&&end[0]==0&&end[1]==0&&end[2]==0)
            break;
        if (temp[0]+temp[1]+temp[2]!=end[0]+end[1]+end[2])
        {
            cout<<"No"<<endl;
            continue;
        }
        stable_sort(temp,temp+3);
        stable_sort(end,end+3);
        for (int i=end[0];i<=end[2];i++)
            use[i].reset();
        Q.clear();
        a.x=temp[0];
        a.y=temp[1];
        a.z=temp[2];
        Q.push_back(a);
        finish=0;
        while (Q.empty()==0)
        {
            a=Q.front();
            Q.pop_front();
            int x=a.x,y=a.y,z=a.z;
            if (x==end[0]&&z==end[2])
            {
                finish=1;
                break;
            }
            if (test(x,y,z))
                Q.push_back(a);
            if (test(y,x,z))
                Q.push_back(a);
            if (test(x,z,y))
                Q.push_back(a);
            if (test(z,x,y))
                Q.push_back(a);
            if (test(z,y,x))
                Q.push_back(a);
            if (test(y,z,x))
                Q.push_back(a);
        }
        if (finish)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
