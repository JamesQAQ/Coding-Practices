#include <cstdio>
#include <algorithm>

int score[200000],power[200000],t[200000];
int a[200000],b[200000];
int input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    int x=c-48;c=getchar();
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
bool cmp(int i,int j){
    if (score[i]>score[j])
        return true;
    if (score[i]<score[j])
        return false;
    return i<j;
}
int swap(int &a,int &b){
    a^=b^=a^=b;
}
int main()
{
    int n,r,q;
    n=2*input(),r=input(),q=input();
    for (int i=0;i<n;i++)
        score[i]=input();
    for (int i=0;i<n;i++)
        power[i]=input(),t[i]=i;
    std::stable_sort(t,t+n,cmp);
    for (int i=0;i<r;i++){
        for (int j=0;j<n;j+=2){
            if (power[t[j]]>power[t[j+1]]){
                a[j/2]=t[j];
                b[j/2]=t[j+1];
                score[t[j]]++;
            }
            else{
                a[j/2]=t[j+1];
                b[j/2]=t[j];
                score[t[j+1]]++;
            }
        }
        int ata=0,atb=0;
        for (int j=0;j<n;j++){
            if (ata>=n/2||(score[a[ata]]<score[b[atb]]||(score[a[ata]]==score[b[atb]]&&a[ata]>b[atb])))
                t[j]=b[atb++];
            else
                t[j]=a[ata++];
        }
    }
    printf("%d\n",t[q-1]+1);
}
