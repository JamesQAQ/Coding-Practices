#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string s,temp;
    int ans=0;
    while (getline(cin,s)){
        stringstream ss(s);
        while (ss>>temp){
            bool one=0;
            for (int i=0;i<temp.length();i++)
                if ((temp[i]<='z'&&temp[i]>='a')||(temp[i]<='Z'&&temp[i]>='A')||(temp[i]<='9'&&temp[i]>='0')){
                    one=1;
                    break;
                }
            if (one) ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
