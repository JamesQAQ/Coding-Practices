#include <iostream>
using namespace std;

string name[8];
int score[8],t[8],ab[8],in[8],out[8];
bool cmp(int i,int j)
{
    if (ab[i]<ab[j]) return 1;
    if (ab[i]>ab[j]) return 0;
    if (score[i]>score[j]) return 1;
    if (score[i]<score[j]) return 0;
    if (in[i]>in[j]) return 1;
    if (in[i]<in[j]) return 0;
    if (out[i]<out[j]) return 1;
    if (out[i]>out[j]) return 0;
    if (name[i]<name[j]) return 1;
    return 0;
}
int search(string s)
{
    for (int i=0;i<8;i++)
        if (s==name[i])
            return i;
}
int main()
{
    int n,aat,bat,as,bs;
    string a,b;
    while (cin>>n)
        while (n-->0)
        {
            for (int i=0;i<8;i++)
            {
                cin>>name[i];
                score[i]=0;
                in[i]=0;
                out[i]=0;
                t[i]=i;
                ab[i]=(i<4)?0:1;
            }
            for (int i=0;i<12;i++)
            {
                cin>>a>>as>>bs>>b;
                aat=search(a);
                bat=search(b);
                in[aat]+=as;
                out[aat]+=bs;
                in[bat]+=bs;
                out[bat]+=as;
                if (as>bs)
                    score[aat]+=3;
                else if (as<bs)
                    score[bat]+=3;
                else
                {
                    score[aat]++;
                    score[bat]++;
                }
            }
            stable_sort(t,t+8,cmp);
            cout<<"A1 "<<name[t[0]]<<endl;
            cout<<"A2 "<<name[t[1]]<<endl;
            cout<<"B1 "<<name[t[4]]<<endl;
            cout<<"B2 "<<name[t[5]]<<endl;
            cout<<"BEST3 "<<((score[t[2]]>score[t[6]])?name[t[2]]:name[t[6]])<<endl;
        }
    return 0;
}
