#include <cstdio>
#include <cstring>


char s[50001],t[100100];
int min(int a,int b){
    return (a<b)?a:b;
}
int match(int a,int b){
    int sum=0;
    while (t[a-sum]==t[b+sum])
        sum++;
    return sum;
}
int main()
{
    int l,r,cases,len,z[100100];
    scanf("%d",&cases);
    while (cases--){
        scanf("%s",s);
        len=strlen(s);
        t[0]='!',t[len*2+2]='?',t[len*2+3]='\0';
        for (int i=1;i<=len*2+1;i+=2)
            t[i]='.';
        for (int i=0,j=2;i<len;i++,j+=2)
            t[j]=s[i];
        len=len*2+1;
        z[1]=1;
        l=r=1;
        for (int i=2;i<=len;i++){
            int ii=r-i+l,n=r-i+1;
            if (i>r){
                z[i]=match(i,i);
                l=i-z[i]+1;
                r=i+z[i]-1;
            }
            else if (z[ii]==n){
                z[i]=n+match(i-n,i+n);
                l=i-z[i]+1;
                r=i+z[i]-1;
            }
            else
                z[i]=min(z[ii],n);
        }
        int ans=0;
        for (int i=1;i<=len;i++)
            if (z[i]>ans)
                ans=z[i];
        printf("%d\n",ans-1);
    }
    return 0;
}
