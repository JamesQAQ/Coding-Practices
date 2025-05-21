#include <cstdio>
#include <cstring>

char map[100][100];

int main()
{
	for (int i=0;i<100;i++)
		for (int j=0;j<100;j++)
			map[i][j]=' ';
	char s[100];
	int at=0,maxx=0;
	while (gets(s)){
		if (strcmp(s,"END")==0)
			break;
		int len=strlen(s);
		if (len>maxx)
			maxx=len;
		for (int i=0;i<len;i++)
			map[i][at]=s[i];
		at+=3;
	}
	for (int i=0;i<maxx;i++){
		int index=99;
		while (index>=0&&map[i][index]==' ')
			index--;
		for (int j=0;j<=index;j++)
			putchar(map[i][j]);
		puts("");
	}
}
