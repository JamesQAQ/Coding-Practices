#include <iostream>
using namespace std;

int main()
{
    string s;
    while (getline(cin,s))
    {
        int sum=0;
        if (s[0]>=65 && s[0]<=72)
            sum += 1+((s[0]-5)%10)*9;
        else if (s[0]==73)
            sum += 39;
        else if (s[0]>=74 && s[0]<=75)
            sum += 1+((s[0]-6)%10)*9;
        else if (s[0]>=76 && s[0]<=78)
            sum += 2+((s[0]-6)%10)*9;
        else if (s[0]==79)
            sum += 48;
        else if (s[0]>=80 && s[0]<=86)
            sum += 2+((s[0]-7)%10)*9;
        else if (s[0]==87)
            sum += 21;
        else if (s[0]>=88 && s[0]<=89)
            sum += 3+((s[0]-8)%10)*9;
        else if (s[0]==90)
            sum += 30;
        int c=8;
        for (int i=1;i<9;i++)
            {
            sum += (s[i]-48)*c;
            c--;
            }
        sum += s[9]-48;
        if (sum%10==0)
            cout<<"real"<<endl;
        else
            cout<<"fake"<<endl;
    }
    system ("pause");
    return 0;
}
