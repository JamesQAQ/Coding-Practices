#include <iostream>
using namespace std;

int main()
{
    string s;
    int sum=0;
    while (cin>>s)
    {
        int n=s.length();
        if (s[0]=='-')
            break;
        else if (s[0]=='0')
        {
            for (int i=2;i<n;i++)
            {
                if (s[i]<=57)
                    sum=sum*16+s[i]-48;
                else
                    sum=sum*16+s[i]-55;
            }
            printf("%d\n",sum);
            sum=0;
        }
        else
        {
            for (int i=0;i<n;i++)
                sum=sum*10+s[i]-48;
            printf("0x%X\n",sum);
            sum=0;
        }            
    }
    //system("pause");
    return 0;
}
