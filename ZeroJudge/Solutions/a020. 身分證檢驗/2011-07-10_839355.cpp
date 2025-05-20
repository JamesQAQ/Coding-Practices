#include <cstdio>

int main()
{
    int v[256];
    v['B']=v['N']=v['Z']=0;
    v['A']=v['M']=v['W']=1;
    v['K']=v['Y']=v['L']=2;
    v['J']=v['V']=v['X']=3;
    v['H']=v['U']=4;
    v['G']=v['T']=v['R']=5;
    v['F']=v['S']=6;
    v['E']=v['R']=7;
    v['D']=v['O']=v['Q']=8;
    v['C']=v['I']=v['P']=9;
    char s[20];
    while (scanf("%s",s)!=EOF){
        int sum=v[s[0]];
        for (int i=1;i<9;i++)
            sum+=(s[i]-48)*(9-i);
        sum+=s[9]-48;
        sum%=10;
        (sum==0)?puts("real"):puts("fake");
    }
    return 0;
}
/*
      A=10 台北市     J=18 新竹縣     S=26 高雄縣
      B=11 台中市     K=19 苗栗縣     T=27 屏東縣
      C=12 基隆市     L=20 台中縣     U=28 花蓮縣
      D=13 台南市     M=21 南投縣     V=29 台東縣
      E=14 高雄市     N=22 彰化縣     W=32 金門縣
      F=15 台北縣     O=35 新竹市     X=30 澎湖縣
      G=16 宜蘭縣     P=23 雲林縣     Y=31 陽明山
      H=17 桃園縣     Q=24 嘉義縣     Z=33 連江縣
      I=34 嘉義市     R=25 台南縣
*/
