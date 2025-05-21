#include <cstdio>

char s[100001];
bool p[100001]={};
int cnt[256];
void init(){
p[2]=true;
for (int i=3;i<=100000;i+=2)
p[i]=true;
for (int i=3;i<=1000;i+=2)
if (p[i])
for (int j=i*i;j<=100000;j+=2*i)
p[j]=false;
}
int main()
{
init();
int cases;
scanf("%d",&cases);
for (int t=1;t<=cases;t++){
scanf("%s",s);
for (int i=0;i<256;i++)
cnt[i]=0;
for (int i=0;s[i];i++)
cnt[s[i]]++;
printf("Case %d: ",t);
bool one=false;
for (int i=0;i<256;i++)
if (p[cnt[i]])
putchar(i),one=true;
if (!one)
printf("empty");
puts("");
}
}
