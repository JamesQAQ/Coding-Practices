#include <cstdio>

char s[3][100];
char QAQ[3][100]={" _     _  _     _  _  _  _  _ "
				 ,"| |  | _| _||_||_ |_   ||_||_|"
				 ,"|_|  ||_  _|  | _||_|  ||_| _|"};
bool same(int a,int b){
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			if (s[i][a+j]!=QAQ[i][b+j])
				return false;
	return true;
}
int check(int x){
	for (int i=0;i<30;i+=3)
		if (same(x,i))
			return i/3;
	return -1;
}
bool checkvalue(int a[]){
	int sum=0;
	for (int i=0;i<9;i++)
		sum+=a[i]*(i+2);
	return sum%11==0;
}
void work(){
	int a[10],pos,cnt=0;
	for (int i=0;i<9;i++){
		a[i]=check(3*i);
		if (a[i]==-1)
			cnt++,pos=i;
	}
	if (cnt>1)
		puts("failure");
	else if (cnt==0){
		if (checkvalue(a)){
			for (int i=0;i<9;i++)
				printf("%d",a[i]);
			puts("");
		}
		else
			puts("failure");
	}
	else{
		int ans=0,ansQQ;
		if (s[0][3*pos+1]==' '){
			s[0][3*pos+1]='_';
			a[pos]=check(3*pos);
			if (a[pos]!=-1&&checkvalue(a))
				ans++,ansQQ=a[pos];
			s[0][3*pos+1]=' ';
		}
		if (s[1][3*pos]==' '){
			s[1][3*pos]='|';
			a[pos]=check(3*pos);
			if (a[pos]!=-1&&checkvalue(a))
				ans++,ansQQ=a[pos];
			s[1][3*pos]=' ';
		}
		if (s[1][3*pos+1]==' '){
			s[1][3*pos+1]='_';
			a[pos]=check(3*pos);
			if (a[pos]!=-1&&checkvalue(a))
				ans++,ansQQ=a[pos];
			s[1][3*pos+1]=' ';
		}
		if (s[1][3*pos+2]==' '){
			s[1][3*pos+2]='|';
			a[pos]=check(3*pos);
			if (a[pos]!=-1&&checkvalue(a))
				ans++,ansQQ=a[pos];
			s[1][3*pos+2]=' ';
		}
		if (s[2][3*pos]==' '){
			s[2][3*pos]='|';
			a[pos]=check(3*pos);
			if (a[pos]!=-1&&checkvalue(a))
				ans++,ansQQ=a[pos];
			s[2][3*pos]=' ';
		}
		if (s[2][3*pos+1]==' '){
			s[2][3*pos+1]='_';
			a[pos]=check(3*pos);
			if (a[pos]!=-1&&checkvalue(a))
				ans++,ansQQ=a[pos];
			s[2][3*pos+1]=' ';
		}
		if (s[2][3*pos+2]==' '){
			s[2][3*pos+2]='|';
			a[pos]=check(3*pos);
			if (a[pos]!=-1&&checkvalue(a))
				ans++,ansQQ=a[pos];
			s[2][3*pos+2]=' ';
		}
		if (ans>1)
			puts("ambiguous");
		else if (ans==0)
			puts("failure");
		else{
			a[pos]=ansQQ;
			for (int i=0;i<9;i++)
				printf("%d",a[i]);
			puts("");
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	gets(s[0]);
	while (n--){
		for (int i=0;i<3;i++)
			gets(s[i]);
		work();
	}
}

/*
5
    _  _     _  _  _  _  _ 
  | _| _||_||_ |_   ||_||_|
  ||_  _|  | _||_|  ||_| _|
    _  _     _  _  _  _    
  | _| _||_||_ |_   ||_|  |
  ||_  _|  | _||_|  ||_|  |
    _  _  _  _  _  _     _ 
|_||_|| || ||_   |  |  || |
  | _||_||_||_|  |  |  | _|
 _  _  _  _  _  _  _  _  _ 
|_||_||_||_||_||_||_||_||_|
|_||_||_||_||_||_||_||_||_|
 _  _  _  _  _  _  _  _  _ 
|_|   |_||_||_||_||_||_||_|
|_|  ||_||_||_||_||_||_||_|
*/
