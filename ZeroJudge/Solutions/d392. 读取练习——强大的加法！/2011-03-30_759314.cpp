#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string s;
    while (getline(cin,s)){
        int sum=0,temp;
        stringstream ss(s);
        while (ss>>temp)
            sum+=temp;
        printf("%d\n",sum);
    }
    return 0;
}
