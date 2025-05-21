#include <iostream>
#include <sstream>
using namespace std;

char operators[10000];
long long _count[10000],c_top,isp[60],icp[60],o_top;
void count_num(char c)
{
    if (c=='+')
    {
        c_top--;
        _count[c_top-1]+=_count[c_top];
    }
    else if (c=='-')
    {
        c_top--;
        _count[c_top-1]-=_count[c_top];
    }
    else if (c=='*')
    {
        c_top--;
        _count[c_top-1]*=_count[c_top];
    }
    else if (c=='/')
    {
        c_top--;
        _count[c_top-1]/=_count[c_top];
    }
    else
    {
        c_top--;
        _count[c_top-1]%=_count[c_top];
    }
}
int main()
{
    isp['+']=icp['+']=isp['-']=icp['-']=1;
    isp['/']=icp['/']=isp['*']=icp['*']=isp['%']=icp['%']=2;
    isp[')']=icp[')']=3;
    isp['(']=0;
    icp['(']=4;
    string s,temp;
    while (getline(cin,s))
    {
        o_top=c_top=0;
        stringstream ss(s);
        while (ss>>temp)
        {
            if (temp.length()==1&&temp[0]<48)
            {
                if (temp[0]==')')
                {
                    while (operators[o_top-1]!='(')
                    {
                        //cout<<operators[o_top-1]<<" ";
                        count_num(operators[o_top-1]);
                        o_top--;
                    }
                    o_top--;
                }
                else if (o_top==0||icp[temp[0]]>isp[operators[o_top-1]])
                    operators[o_top++]=temp[0];
                else
                {
                    while (o_top>0&&isp[operators[o_top-1]]>=isp[temp[0]])
                    {
                        //cout<<operators[o_top-1]<<" ";
                        count_num(operators[o_top-1]);
                        o_top--;
                    }
                    o_top++;
                    operators[o_top-1]=temp[0];
                }
            }
            else
            {
                //cout<<temp<<" ";
                stringstream stemp(temp);
                stemp>>_count[c_top++];
            }
        }
        while (o_top>0)
        {
            //cout<<operators[o_top-1]<<" ";
            count_num(operators[o_top-1]);
            o_top--;
        }
        cout<<_count[0]<<endl;
    }
    return 0;
}
