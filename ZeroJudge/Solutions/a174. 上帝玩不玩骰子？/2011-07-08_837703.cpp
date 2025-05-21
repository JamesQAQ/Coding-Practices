#include <cstdio>

int k,m,step,n,num;
struct Node {int x,list;} hash[10200];
int input(){
	char c=getchar();
	while (c==' '||c=='\n')
		c=getchar();
	int x=c-48;
	c=getchar();
	while (c!=' '&&c!='\n'){
		x=x*10+c-48;
		c=getchar();
	}
	return x;
}
void print(){
	puts("===== s =====");
	for (int i=0;i<m;i++){
		printf("[%03d]:",i);
		int at=hash[i].list;
		while (at!=-1){
			printf("%d -> ",hash[at].x);
			at=hash[at].list;
		}
		puts("NULL");
	}
	puts("===== e =====");
}
void insert(int x){
	int f=x%m,at=hash[f].list;
	while (at!=-1){
		if (hash[at].x==x)
			return;
		if (hash[at].x>x)
			break;
		f=at,at=hash[at].list;
	}
	hash[num].list=hash[f].list;
	hash[f].list=num;
	hash[num].x=x;
	num++;
}
void del(int x){
	int f=x%m,at=hash[f].list;
	while (at!=-1){
		if (hash[at].x==x){
			hash[f].list=hash[at].list;
			return;
		}
		f=at,at=hash[at].list;
	}
}
int main()
{
	while (scanf("%d %d",&k,&m)==2){
		num=m;
		for (int i=0;i<m;i++)
			hash[i].list=-1;
		for (int i=0;i<k;i++){
			step=input();
			if (step==3)
				print();
			else if (step==1){
				n=input();
				insert(n);
			}
			else{
				n=input();
				del(n);
			}
		}
	}
	return 0;
}
