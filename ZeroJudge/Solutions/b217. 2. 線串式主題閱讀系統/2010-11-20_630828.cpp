#include <iostream>
#include <sstream>
#include <iostream>
using namespace std;

struct Node {int id,m,d,h,y,n;string t;} data[10000];
int num;
string temp;

bool cmp(Node i,Node j)
{
    if (i.y<j.y) return 1;
    if (i.y>j.y) return 0;
    if (i.m<j.m) return 1;
    if (i.m>j.m) return 0;
    if (i.d<j.d) return 1;
    if (i.d>j.d) return 0;
    if (i.h<j.h) return 1;
    if (i.h>j.h) return 0;
    if (i.n<j.n) return 1;
    return 0;
}
void subject()
{
    temp.erase(0,9);
    if (temp.substr(0,3)=="Re:"||temp.substr(0,3)=="RE:")
        temp.erase(0,3);
    int l=0,r=temp.length()-1;
    while (temp[l]==' ')
        l++;
    while (temp[r]==' ')
        r--;
    data[num].t=temp.substr(l,r-l+1);
}
void date()
{
    stringstream ss(temp);
    string s;
    ss>>s>>data[num].m>>data[num].d>>data[num].h>>data[num].y;
}
void id()
{
    stringstream ss(temp);
    string s;
    ss>>s>>data[num].id;
}
int main()
{
    while (getline(cin,temp))
    {
        num=0;
        subject();
        getline(cin,temp);
        date();
        getline(cin,temp);
        id();
        data[num].n=num++;
        getline(cin,temp);
        while (getline(cin,temp))
        {
            if (temp.length()==0)
                break;
            subject();
            getline(cin,temp);
            date();
            getline(cin,temp);
            id();
            data[num].n=num++;
            getline(cin,temp);
        }
        stable_sort(data,data+num,cmp);
        string ans1=data[0].t,ans2;
        int x=1;
        while (data[x].t==ans1)
            x++;
        ans2=data[x].t;
        cout<<"Subject: "<<ans1<<endl;
        cout<<"ID: "<<data[0].id;
        for (int i=1;i<num;i++)
            if (data[i].t==ans1)
                cout<<","<<data[i].id;
        cout<<endl;
        cout<<"Subject: "<<ans2<<endl;
        cout<<"ID: "<<data[x].id;
        for (int i=x+1;i<num;i++)
            if (data[i].t==ans2)
                cout<<","<<data[i].id;
        cout<<endl;
    }
    return 0;
}
