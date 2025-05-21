#include <cstdio>
#include <iostream>
using namespace std;

string sBrand[20],sColor[20];
int main(){
    bool first=true;
    int n,m;
    string tag,name;
    while (scanf("%d %d",&n,&m)==2){
        if (first) first=false;
        else puts("");
        for (int i=0;i<n;i++)
            cin>>sBrand[i]>>sColor[i];
        for (int i=0;i<m;i++){
            cin>>tag>>name;
            if (tag=="color"){
                for (int j=0;j<n;j++)
                    if (name==sColor[j])
                        cout<<sBrand[j]<<" "<<sColor[j]<<"\n";
            }
            else{
                for (int j=0;j<n;j++)
                    if (name==sBrand[j])
                        cout<<sBrand[j]<<" "<<sColor[j]<<"\n";
            }
        }
    }
}
