#include <stdio.h>
#include <cstring>

void work(char s[]){
	int x=0;
	for (int i=0;s[i];i++)
		x=x+((i&1)?1:-1)*(s[i]-48);
	if (x%11==0)
		printf("%s is a multiple of 11.\n",s);
	else
		printf("%s is not a multiple of 11.\n",s);
}
int main()
{
	char s[1001];
	while (scanf("%s",s)){
		if (strcmp(s,"0")==0)
			break;
		work(s);
	}
}
