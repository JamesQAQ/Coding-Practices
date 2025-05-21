#include <cstdio>
#include <cstring>

char s[10000];
void get(int a[],int &num){
	scanf("%s",s);
	num=strlen(s);
	for (int i=0;i<num;i++)
		a[i]=s[num-i-1]-48;
}
void fix(int a[],int &num){
	while (num&&a[num-1]==0)
		num--;
}
void swap(int &a,int &b){
	a^=b^=a^=b;
}
void reverse(int a[],int &num){
	for (int i=0;i<num/2;i++)
		swap(a[i],a[num-i-1]);
}
int main()
{
	int n;
	int a[10000],b[10000],anum,bnum;
	scanf("%d",&n);
	while (n--){
		get(a,anum);
		fix(a,anum);
		reverse(a,anum);
		fix(a,anum);
		get(b,bnum);
		fix(b,bnum);
		reverse(b,bnum);
		fix(b,bnum);
		if (bnum>anum){
			for (int i=anum;i<bnum;i++)
				a[i]=0;
			anum=bnum;
		}
		for (int i=0;i<bnum;i++)
			a[i]+=b[i];
		for (int i=0;i<anum-1;i++)
			if (a[i]>=10){
				a[i]-=10;
				a[i+1]++;
			}
		if (a[anum-1]>=10){
			a[anum]=1;
			a[anum-1]-=10;
			anum++;
		}
		reverse(a,anum);
		fix(a,anum);
		if (anum==0)
			printf("0");
		for (int i=anum-1;i>=0;i--)
			printf("%d",a[i]);
		puts("");
	}
}
