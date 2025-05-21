#include <iostream>
using namespace std;

int main()
{
    int n,k=0,sum=0;
    string s;
    char math_word[27]={"mjqhofawcpnsexdkvgtzblryui"};
    char word_math[27]={"uzrmatifxopnhwvbslekycqjgd"};
    while (cin>>n)
    {
        getline (cin,s);
        for (int i=0;i<n;i++)
        {
            getline (cin,s);
            int y=s.length();
            int i=0;
            for (;i<y;i++)
                if (s[i]==32)
                    break;
            i++;
            if ((s[i]<=57)&&(s[i]>=48))
            {
                for (;i<y;i++)
                {
                    if (s[i]==32)
                    {
                        cout<<math_word[k-1];
                        k=0;
                    }
                    else
                        k=k*10+s[i]-48;
                }
                cout<<math_word[k-1]<<endl;
                k=0;
            }
            else
            {
                for (;i<y;i++)
                {
                    if (s[i]!=32)
                    {
                        for (int o=0;o<26;o++)
                        {
                            if (s[i]==word_math[o])
                                sum+=o+1;
                        }
                    }
                }
                cout<<sum<<endl;
                sum=0;
            }
        }
    }
    //system ("pause");
    return 0;
}
