#include <cstdio>

int sumA,sumB,po;
int map[10][7]={{1,1,1,0,1,1,1}
			   ,{0,0,1,0,0,1,0}
			   ,{1,0,1,1,1,0,1}
			   ,{1,0,1,1,0,1,1}
			   ,{0,1,1,1,0,1,0}
			   ,{1,1,0,1,0,1,1}
			   ,{1,1,0,1,1,1,1}
			   ,{1,0,1,0,0,1,0}
			   ,{1,1,1,1,1,1,1}
			   ,{1,1,1,1,0,1,1}};
int pow[10000];
bool run(char s[]){
	int i,x=0,a=0,b=0;
	bool op=true;
	for (i=0;s[i]!='=';i++){
		if (s[i]<='9'&&s[i]>='0')
			x=x*10+s[i]-'0';
		else{
			if (op)
				a+=x;
			else
				a-=x;
			x=0;
			if (s[i]=='-')
				op=false;
			else
				op=true;
		}
	}
	if (op)
		a+=x;
	else
		a-=x;
	x=0;
	po=i;
	i++;
	op=true;
	for (;s[i]!='#';i++){
		if (s[i]<='9'&&s[i]>='0')
			x=x*10+s[i]-'0';
		else{
			if (op)
				b+=x;
			else
				b-=x;
			x=0;
			if (s[i]=='-')
				op=false;
			else
				op=true;
		}
	}
	if (op)
		b+=x;
	else
		b-=x;
	s[i+1]='\0';
	sumA=a,sumB=b;
	int ttmp=1;
	while (i>=0){
		if (s[i]>'9'||s[i]<'0')
			ttmp=1;
		else{
			pow[i]=ttmp;
			ttmp*=10;
		}
		i--;
	}
	bool QAQQQQQ=true;
	for (int i=0;s[i]!='#';i++){
		if (s[i]=='+'||s[i]=='=')
			QAQQQQQ=true;
		else if (s[i]=='-')
			QAQQQQQ=false;
		if (!QAQQQQQ)
			pow[i]=-pow[i];
	}
	return a==b;
}
bool chmyself(int a,int b){
	int A=0,B=0;
	for (int i=0;i<7;i++){
		if (map[a][i]-map[b][i]==1)
			A++;
		else if (map[a][i]-map[b][i]==-1)
			B++;
	}
	return A==1&&B==1;
}
char S[10000];
int no[128];
void init(){
	for (int i=0;i<128;i++)
		no[i]=-1;
	for (int i=0;i<10;i++){
		int x=0;
		for (int j=0;j<7;j++)
			x=2*x+map[i][j];
		no[x]=i;
	}
}
int find(int a[]){
	int x=0;
	for (int i=0;i<7;i++)
		x=2*x+a[i];
	return no[x];
}
bool work(int a,int b){
	char tmpa=S[a],tmpb=S[b];
	int A[7],B[7];
	for (int i=0;i<7;i++)
		A[i]=map[S[a]-'0'][i],B[i]=map[S[b]-'0'][i];
	for (int i=0;i<7;i++)
		for (int j=0;j<7;j++){
			if (A[i]==1&&B[j]==0){
				A[i]--;
				B[j]++;
				int pa=find(A),pb=find(B);
				if (pa!=-1&&pb!=-1){
					S[a]=pa+'0';
					S[b]=pb+'0';
					int tsumA=sumA,tsumB=sumB;
					if (a<po)
						tsumA+=(pa-(tmpa-'0'))*pow[a];
					else
						tsumB+=(pa-(tmpa-'0'))*pow[a];
					if (b<po)
						tsumA+=(pb-(tmpb-'0'))*pow[b];
					else
						tsumB+=(pb-(tmpb-'0'))*pow[b];
					if (tsumA==tsumB){
						puts(S);
						return true;						
					}
				}
				A[i]++;
				B[j]--;
			}
		}
	S[a]=tmpa,S[b]=tmpb;
	return false;
}
int main()
{
	init();
	scanf("%s",S);
	if (run(S)){
		puts(S);
		return 0;
	}
	for (int i=0;S[i];i++)
		if (S[i]<='9'&&S[i]>='0')
			for (int j=0;S[j];j++)
				if (S[j]<='9'&&S[j]>='0'){
					if (i==j){
						char tmp=S[i];
						for (int k=0;k<10;k++)
							if (chmyself(S[i]-'0',k)){
								S[i]=k+'0';
								int tsumA=sumA,tsumB=sumB;
								if (i<po)
									tsumA+=(k-(tmp-'0'))*pow[i];
								else
									tsumB+=(k-(tmp-'0'))*pow[i];
								if (tsumA==tsumB){
									puts(S);
									return 0;
								}
							}
						S[i]=tmp;
					}
					else if (work(i,j))
						return 0;
				}
	puts("No");
}
