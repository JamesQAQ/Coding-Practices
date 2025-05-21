#include <cstdio>

void arraycat(int a[],int &len,int x){
	int tmp[10],num=0;
	while (x){
		tmp[num++]=x%10;
		x/=10;
	}
	for (int i=0;i<num;i++)
		a[i+len]=tmp[num-i-1];
	len+=num;
}
void cut(int a[],int &len){
	for (int i=0;i<len-1;i++)
		a[i]=(a[i]+a[i+1])%10;
	len--;
}
bool ok(char s[],int st){
	int a[100],len=0;
	for (int i=0;s[i];i++)
		arraycat(a,len,s[i]+st-'A');
	while (len>3)
		cut(a,len);
	if (len==3)
		return a[0]==1&&a[1]==0&&a[2]==0;
	else
		return false;
}
void work(char s[]){
	for (int i=1;i<=10000;i++)
		if (ok(s,i)){
			printf("%d\n",i);
			return;
		}
	puts(":(");
}
int main()
{
	char s[1000];
	//scanf("%s",s);
	//ok(s,81);
	int st;
	while (scanf("%s",s)==1)
		work(s);
}
