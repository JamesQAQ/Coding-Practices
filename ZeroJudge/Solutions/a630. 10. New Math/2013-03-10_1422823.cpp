#include <cstdio>
#include <cstring>

int v[256];
long long stack[10000];
int top;
long long op[10000];
bool opr[10000];
int num;
char s[1000000];
char cha[100];
long long ch(int l,int r,int base){
	long long x=0;
	for (int i=l;i<=r;i++)
		x=x*base+v[s[i]];
	return x;
}
int instack[100];
void print(long long x,int base){
	char ts[100];
	int num=0;
	if (x<0)
		putchar('-'),x=-x;
	while (x!=0){
		ts[num++]=cha[x%base];
		//printf("x%%base %d\n",x%base);
		x/=base;
	}
	for (int i=num-1;i>=0;i--)
		putchar(ts[i]);
	printf("^%d\n",base);
}
int main()
{
	instack['+']=instack['-']=0;
	instack['*']=1;
	for (int i=0;i<10;i++)
		v[i+'0']=i,cha[i]=i+'0';
	for (int i=0;i<26;i++)
		v[i+'a']=i+10,cha[i+10]=i+'a';
	while (scanf("%s",s)==1){
		top=0;
		num=0;
		for (int i=0;s[i];i++){
			int l=i,r,pos;
			for (int j=l;;j++){
				if (s[j]=='+'||s[j]=='-'||s[j]=='*'||s[j]=='='){
					r=j-1;
					break;
				}
				if (s[j]=='^')
					pos=j;
			}
			op[num]=ch(l,pos-1,ch(pos+1,r,10));
			opr[num]=false;
			num++;
			if (s[r+1]=='=')
				break;
			while (top&&instack[stack[top-1]]>=instack[s[r+1]])
				op[num]=stack[top-1],opr[num]=true,num++,top--;
			stack[top++]=s[r+1];
			i=r+1;
		}
		while (top)
			op[num]=stack[top-1],opr[num]=true,num++,top--;
			
		/*for (int i=0;i<num;i++){
			if (opr[i])
				printf(" %c ",op[i]);
			else
				printf(" %lld ",op[i]);
		}
		puts("");*/
			
		for (int i=0;i<num;i++){
			if (opr[i]){
				top--;
				if (op[i]=='+')
					stack[top-1]+=stack[top];
				else if (op[i]=='-')
					stack[top-1]-=stack[top];
				else
					stack[top-1]*=stack[top];
			}
			else{
				stack[top++]=op[i];
				//printf(" %lld ",op[i]);
			}
		}
		int len=strlen(s),endbase;
		for (int i=len-1;;i--)
			if (s[i]=='^'){
				endbase=ch(i+1,len-1,10);
				break;
			}
		print(stack[0],endbase);
	}
}
/*
1b^13+j3a67^20-hhh^19+123^6*123^7=^15
1db7^14+egg^18-hi32^20+3876^9-321^4=^7
1db7^14+egg^18+hi32^20*3876^9*30^19-110a62^18+321^4=^20
*/
