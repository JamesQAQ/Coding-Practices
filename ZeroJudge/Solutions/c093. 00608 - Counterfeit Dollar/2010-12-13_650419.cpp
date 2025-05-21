#include <iostream>
using namespace std;

int main()
{
    short state[12];
    bool fail[12];
    string L,R,temp;
    int l,r,t;
    char ans;
    while (cin>>t)
        while (t-->0)
        {
            memset(state,0,sizeof(state));
            memset(fail,0,sizeof(fail));
            ans=12+'A';
            for (int i=0;i<3;i++)
            {
                cin>>L>>R>>temp;
                if (temp=="even")
                {
                    l=2;
                    r=2;
                }
                else if (temp=="up")
                {
                    l=3;
                    r=1;
                }
                else
                {
                    l=1;
                    r=3;
                }
                int len=L.length();
                for (int j=0;j<len;j++)
                {
                    int ll=L[j]-'A',rr=R[j]-'A';
                    if (state[ll]==0)
                        state[ll]=l;
                    else if (state[ll]!=l)
                    {
                        state[ll]=2;
                        fail[ll]=0;
                    }
                    else if (state[ll]!=2)
                        fail[ll]=1;
                    if (state[rr]==0)
                        state[rr]=r;
                    else if (state[rr]!=r)
                    {
                        state[rr]=2;
                        fail[rr]=0;
                    }
                    else if (state[rr]!=2)
                        fail[rr]=1;
                }
            }
            for (int i=0;i<12;i++)
                if (fail[i])
                {
                    ans=i+'A';
                    break;
                }
            if (ans==12+'A')
                for (int i=0;i<12;i++)
                    if (state[i]==1||state[i]==3)
                    {
                        ans=i+'A';
                        break;
                    }
            cout<<ans<<" is the counterfeit coin and it is "<<((state[ans-'A']==1)?"light":"heavy")<<"."<<endl;
        }
    return 0;
}
