#include <cstdio>

int v[128];
int GetNumber(char s[]){
    int i,sum=0;
    for (i=0;s[i+1];i++){
        if (v[s[i]]<v[s[i+1]])
            sum-=v[s[i]];
        else
            sum+=v[s[i]];
    }
    sum+=v[s[i]];
    return sum;
}
char tens[7][10]={"","X","XX","XXX","IL","L","LI"};
char ds[10][10]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
void print(int x){
    printf("%s%s",tens[x/10],ds[x%10]);
    puts("");
}
int main()
{
    v['I']=1,v['V']=5,v['X']=10,v['L']=50;
    char H[100],M[100];
    while (scanf("%s %s",H,M)==2){
        int h=GetNumber(H),m=GetNumber(M);
        m+=30;
        if (m>=60)
            m-=60,h++;
        h+=7;
        if (h>24)
            h-=24;
        print(h),print(m);
    }
}
