#include <sstream>
#include <iostream>
using namespace std;

int a[1000],sum[1000],num;
void search(int x){
    for (int i=0;i<num;i++)
        if (x==a[i]){
            sum[i]++;
            return;
        }
    a[num]=x;
    sum[num++]=1;
}
int main()
{
    string s;
    int temp;
    while (getline(cin,s)){
        num=0;
        stringstream ss(s);
        while (ss>>temp)
            search(temp);
        for (int i=0;i<num;i++)
            if (sum[i]==2){
                printf("%d\n",a[i]);
                break;
            }
    }
    return 0;
}
