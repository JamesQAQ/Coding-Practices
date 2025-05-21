#include <cstdio>

int stack[2000000],top,a[2000000];
bool work(int n){
	top=0;
	int at=1,tmp;
	for (int i=0;i<n;i++){
		//printf("i %d\n",i);
		tmp=a[i];
		while (at<=tmp)
			stack[top++]=at++;
		if (stack[top-1]!=tmp)
			return false;
		top--;
	}
	return true;
}
int main()
{
	int n,cases;
	while (scanf("%d",&n),n){
		while (scanf("%d",&a[0]),a[0]){
			for (int i=1;i<n;i++)
				scanf("%d",&a[i]);
			puts((work(n))?"Yes":"No");
		}
		puts("");
	}
}
