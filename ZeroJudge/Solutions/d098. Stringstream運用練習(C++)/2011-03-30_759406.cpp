#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string s,temp;
    while (getline(cin,s)){
        int ans=0,a;
        stringstream ss(s);
        while (ss>>temp){
            bool one=1;
            for (int i=0;i<temp.length();i++)
                if (!(temp[i]>='0'&&temp[i]<='9')){
                    one=0;
                    break;
                }
            if (one){
                stringstream sss(temp);
                sss>>a;
                ans+=a;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
