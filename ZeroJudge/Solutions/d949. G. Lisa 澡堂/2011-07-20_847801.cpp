#include <cstdio>

int lisa[601],gaspard[601],n;
bool use[601];
int input(){
    char c=getchar();
    while (c==' '||c=='\n')
        c=getchar();
    int x=c-48;
    c=getchar();
    while (c!=' '&&c!='\n'){
        x=x*10+c-48;
        c=getchar();
    }
    return x;
}
bool test(int x){
    int atl=1,atg=1,suml=0,sumg=0;
    for (int i=1;i<=n;i++){
        use[i]=false;
        while (lisa[i]-suml>x){
            if (atl>i)
                return false;
            if (!use[atl]&&lisa[atl-1]>suml){
                use[atl]=true;
                suml++;
            }
            atl++;
        }
        while (gaspard[i]-sumg>x){

            if (atg>i)
                return false;
            if (!use[atg]&&gaspard[atg-1]>sumg){
                use[atg]=true;
                sumg++;
            }
            atg++;
        }
    }
    return true;
}
int main()
{
    int cases;
    cases=input();
    while (cases--){
        n=input();
        lisa[0]=gaspard[0]=0;
        for (int i=1;i<=n;i++){
            lisa[i]=input();
            gaspard[i]=input();
        }
        for (int i=1;i<=n;i++)
            lisa[i]+=lisa[i-1],gaspard[i]+=gaspard[i-1];
        int l=0,r=(lisa[n-1]>gaspard[n-1])?lisa[n-1]:gaspard[n-1],mid;
        while (l<=r){
            mid=(l+r)/2;
            if (test(mid)) r=mid-1;
            else l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}
