#include <cstdio>

char s[10];
char stack[1000];
int instack[256],atstack[256];
int main()
{
	instack['(']=3;
	instack['+']=instack['-']=1;
	instack['*']=instack['/']=2;
	atstack['(']=0;
	atstack['+']=atstack['-']=1;
	atstack['*']=atstack['/']=2;
	int top=0;
	bool first=true;
	gets(s);
	while (gets(s)!=NULL){
		if (s[0]=='\0'||s[0]==' '){
			//puts("QAQ");
			if (first) first=false;
			else{
				while (top)
					putchar(stack[--top]);
				puts("");
			}
		}
		else{
			if (s[0]<='9'&&s[0]>='0')
				putchar(s[0]);
			else{
				if (s[0]==')'){
					while (stack[top-1]!='(')
						putchar(stack[--top]);
					top--;
				}
				else{
					while (atstack[stack[top-1]]>=instack[s[0]])
						putchar(stack[--top]);
					stack[top++]=s[0];
				}
			}
		}
	}
	while (top)
		putchar(stack[--top]);
	puts("");
}
