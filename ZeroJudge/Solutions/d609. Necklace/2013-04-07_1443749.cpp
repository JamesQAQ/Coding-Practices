/*
ID: luniacs1
PROG: beads
LANG: C++
*/
#include <stdio.h>

int n;
char s[1000];
int left[1000],righ[1000];
int main()
{
	int n;
	while (scanf("%d",&n)==1){
	scanf("%s",s);
	for (int i=0;i<n;i++)
		s[i+n]=s[i];
	char tmp=' ';
	int cnw=0,cnt=0;
	for (int i=0;i<2*n;i++){
		if (s[i]=='w'){
			cnw++;
			cnt++;
		}
		else if (s[i]!=tmp){
			cnt=1+cnw;
			cnw=0;
			tmp=s[i];
		}
		else{
			cnt++;
			cnw=0;
		}
		left[i]=cnt;
	}
	cnw=0,cnt=0;
	for (int i=2*n-1;i>=0;i--){
		if (s[i]=='w'){
			cnw++;
			cnt++;
		}
		else if (s[i]!=tmp){
			cnt=1+cnw;
			cnw=0;
			tmp=s[i];
		}
		else{
			cnt++;
			cnw=0;
		}
		righ[i]=cnt;
	}
	int ans=0;
	for (int i=0;i<2*n-1;i++)
		if (left[i]+righ[i+1]>ans)
			ans=left[i]+righ[i+1];
	if (ans>n) ans=n;
	printf("%d\n",ans);}
}

/*
29
wwwbbrwrbrbrrbrbrwrwwrbwrwrrb
*/
