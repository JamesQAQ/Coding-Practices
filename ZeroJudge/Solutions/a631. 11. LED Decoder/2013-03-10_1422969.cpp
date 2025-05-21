#include <cstdio>
#include <cstring>

char a[26][20]={"123457"
			   ,"1234567"
			   ,"456"
			   ,"1580"
			   ,"12456"
			   ,"1249"
			   ,"12569"
			   ,"13457"
			   ,"37"
			   ,"3567"
			   ,"13459"
			   ,"156"
			   ,"12357"
			   ,"3579"
			   ,"123567"
			   ,"1458"
			   ,"12347"
			   ,"123459"
			   ,"12467"
			   ,"278"
			   ,"13567"
			   ,"1379"
			   ,"135790"
			   ,"90"
			   ,"1347"
			   ,"23456"};
bool match(char b[],char s[]){
	//printf("match %s\n",s);
	for (int i=0;b[i];i++)
		if (b[i]!=s[i])
			return false;
	return true;
}
int main()
{
	char s[10000];
	while (gets(s)!=NULL){
		for (int i=0;s[i];i++){
			if (s[i]=='0')
				putchar(' ');
			else if (s[i]<='9'&&s[i]>='1'){
				for (int j=0;j<26;j++)
					if (match(a[j],s+i)){
						putchar(j+'A');
						i+=strlen(a[j])-1;
						break;
					}
			}
			else
				putchar(s[i]);
		}
		puts("");
	}
}
