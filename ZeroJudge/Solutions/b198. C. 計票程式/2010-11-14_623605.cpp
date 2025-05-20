#include <iostream>
using namespace std;

string votecode[1000],temp,name[10000];
int votenum=0,vote[10000],nnum,t[10000];
bool usecode[1000],usename[10000];
bool cmp(int i,int j)
{
    if (vote[i]>vote[j]) return 1;
    if (vote[i]<vote[j]) return 0;
    if (name[i]<name[j]) return 1;
    if (name[i]>name[j]) return 0;
}
int search_code(string s)
{
    int p;
    for (int i=0;i<votenum;i++)
    {
        p=s.find(votecode[i]);
        if (p!=-1)
            return i;
    }
    return -1;
}
int search_vote(string s)
{
    for (int i=0;i<nnum;i++)
        if (s==name[i])
            return i;
    name[nnum++]=s;
    vote[nnum-1]=0;
    t[nnum-1]=nnum-1;
    return nnum-1;
}
int main()
{
    while (getline(cin,votecode[0]))
    {
        usecode[0]=0;
        votenum=1;
        while (getline(cin,votecode[votenum++]))
        {
            if (votecode[votenum-1]=="*")
            {
                votenum--;
                break;
            }
            usecode[votenum-1]=0;
        }
        nnum=0;
        getline(cin,temp);
        while (temp[0]!='*')
        {
            for (int i=0;i<nnum;i++)
                usename[i]=0;
            getline(cin,temp);
            int p=search_code(temp);
            while (getline(cin,temp))
            {
                if (temp[0]!=' ')
                    break;
                if (p==-1||usecode[p])
                    continue;
                if (temp.substr(4,2)=="<<"&&temp.substr(temp.length()-2,2)==">>")
                {
                    int at=search_vote(temp);
                    if (!usename[at])
                    {
                        vote[at]++;
                        usename[at]=1;
                    }
                }
            }
            if (p!=-1)
                usecode[p]=1;
        }
        stable_sort(t,t+nnum,cmp);
        for (int i=0;i<nnum;i++)
            cout<<vote[t[i]]<<" "<<name[t[i]].substr(4,name[t[i]].length()-4)<<endl;
    }
    return 0;
}
