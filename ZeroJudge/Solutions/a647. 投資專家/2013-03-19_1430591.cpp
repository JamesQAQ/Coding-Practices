#include <cstdio>

char s[100];
int num=0;
char tmp[10];
void in(int x){
	int tnum=0;
	if (x==0)
		tmp[tnum++]='0';
	else{
		while (x){
			tmp[tnum++]=x%10+'0';
			x/=10;
		}
	}
	for (int i=tnum-1;i>=0;i--)
		s[num++]=tmp[i];
}
void in2(int x){
	s[num++]=x/10+'0';
	s[num++]=x%10+'0';
}
int main()
{
	int cases,a,b;
	scanf("%d",&cases);
	bool negative;
	while (cases--){
		num=0;
		scanf("%d %d",&a,&b);
		b-=a;
		negative=false;
		if (b<0){
			b=-b;
			s[num++]='-';
			negative=true;
		}
		b*=100000;
		int A=(b/a)/1000,B=((b/a)%1000)/10,C=(b/a)%10;
		int OA=A,OB=B,OC=C;
		//printf("%d %d %d\n",A,B,C);
		if (C>=5)
			B++;
		if (B>=100)
			A++,B-=100;
		in(A);
		s[num++]='.';
		in2(B);
		for (int i=0;i<6-num;i++)
			putchar(' ');
		s[num]=0;
		printf("%s%% ",s);
		bool flag=false;
		if (!negative&&OA<10)
			flag=true;
		if (negative&&OA<7)
			flag=true;
		puts((flag)?"keep":"dispose");
	}
}
