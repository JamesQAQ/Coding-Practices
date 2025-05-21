#include <stdio.h>
#include <algorithm>

char card[2][5][3];
int num[256],col[256];
bool testtonhua(int cnt[]){
    for (int i=0;i<4;i++)
        if (cnt[i]==5)
            return true;
    return false;
}
bool shuenok(int x,int cntnum[]){
    for (int i=0;i<5;i++)
        if (cntnum[i+x]!=1)
            return false;
    return true;
}
bool testshuen(int cntnum[]){
    for (int i=0;i<10;i++)
        if (shuenok(i,cntnum))
            return true;
    return false;
}
int judge(char sc[5][3]){
    int cntnum[14]={},cntcol[4]={},cnt[5]={};
    for (int i=0;i<5;i++){
        cntnum[num[sc[i][0]]]++;
        if (sc[i][0]=='A')
            cntnum[0]++;
        cntcol[col[sc[i][1]]]++;
    }
    for (int i=1;i<=13;i++)
        cnt[cntnum[i]]++;
    int maxx,maxx2,maxx3;
    for (maxx=13;maxx>=0;maxx--)
        if (cntnum[maxx])
            break;
    for (maxx2=maxx-1;maxx2>=0;maxx2--)
        if (cntnum[maxx2])
            break;
    for (maxx3=maxx2-1;maxx3>=0;maxx3--)
        if (cntnum[maxx3])
            break;
    bool tonhua=testtonhua(cntcol),shuen=testshuen(cntnum);
    if (tonhua&&shuen){
        if (maxx==13&&maxx2!=12)
            maxx=maxx2;
        return 900000000+maxx;
    }
    if (cnt[4]){
        if (cntnum[maxx]==1)
            maxx=maxx2;
        return 800000000+maxx;
    }
    if (cnt[3]&&cnt[2]){
        if (cntnum[maxx]==2)
            maxx=maxx2;
        return 700000000+maxx;
    }
    if (tonhua)
        return 600000000+maxx;
    if (shuen){
        if (maxx==13&&maxx2!=12)
            maxx=maxx2;
        return 500000000+maxx;
    }
    if (cnt[3]){
        if (cntnum[maxx2]==3)
            maxx=maxx2;
        else if (cntnum[maxx3]==3)
            maxx=maxx3;
        return 400000000+maxx;
    }
    if (cnt[2]==2){
        if (cntnum[maxx]<2){
            maxx=maxx2;
            maxx2=maxx3;
        }
        else if (cntnum[maxx2]<2)
            maxx2=maxx3;
        return 300000000+maxx*100+maxx2;
    }
    if (cnt[2]){
        int duei;
        for (duei=1;duei<=13;duei++)
            if (cntnum[duei]==2)
                break;
        int w=10000,sum=0;
        for (int i=13;i>=1;i--)
            if (cntnum[i]){
                sum+=w*i;
                w/=100;
            }
        return 200000000+1000000*duei+sum;
    }
    else
        return 0;
}
bool wuduei(char sc1[5][3],char sc2[5][3]){
    int a[5],b[5];
    for (int i=0;i<5;i++)
        a[i]=num[sc1[i][0]];
    for (int i=0;i<5;i++)
        b[i]=num[sc2[i][0]];
    std::stable_sort(a,a+5);
    std::stable_sort(b,b+5);
    for (int i=4;i>=0;i--)
        if (a[i]!=b[i])
            return a[i]>b[i];
}
void build(){
    for (int i='2';i<='9';i++)
        num[i]=i-'0'-1;
    num['T']=9,num['J']=10,num['Q']=11,num['K']=12,num['A']=13;
    col['S']=0,col['H']=1,col['D']=2,col['C']=3;
}
int main()
{
    build();
    int cases;
    scanf("%d",&cases);
    while (cases--){
        for (int i=0;i<2;i++)
            for (int j=0;j<5;j++)
                scanf("%s",card[i][j]);
        int v1=judge(card[0]),v2=judge(card[1]);
        if (v1==0&&v2==0)
            puts((wuduei(card[0],card[1]))?"Win":"Lose");
        else
            puts((v1>v2)?"Win":"Lose");
    }
}
