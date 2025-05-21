#include <cstdio>
#include <cstring>

int eight(char s[]){
	return strlen(s)>=8;
}
int bigsmall(char s[]){
	bool big=false,small=false;
	for (int i=0;s[i];i++){
		if ('A'<=s[i]&&s[i]<='Z')
			big=true;
		if ('a'<=s[i]&&s[i]<='z')
			small=true;
	}
	return big&&small;
}
int special(char s[]){
	bool en=false,ot=false;
	for (int i=0;s[i];i++){
		if (('A'<=s[i]&&s[i]<='Z')||('a'<=s[i]&&s[i]<='z'))
			en=true;
		else
			ot=true;
	}
	return en&&ot;
}
int main()
{
	char s[100];
	while (scanf("%s",s)==1){
		int cnt=eight(s)+bigsmall(s)+special(s);
		if (cnt==0)
			puts("This password is WEAK");
		else if (cnt==1)
			puts("This password is ACCEPTABLE");
		else if (cnt==2)
			puts("This password is GOOD");
		else
			puts("This password is STRONG");
	}
}
/*
This password is WEAK
This password is ACCEPTABLE
This password is GOOD
This password is STRONG
*/
