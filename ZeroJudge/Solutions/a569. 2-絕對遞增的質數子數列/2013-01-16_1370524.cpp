#include <cstdio>

bool p[10000001]={};
void sieve(){
	p[2]=true;
	for (int i=3;i<10000000;i+=2)
		p[i]=true;
	for (int i=3;i<3162;i+=2)
		if (p[i])
			for (int j=i*i;j<10000000;j+=2*i)
				p[j]=false;
}
bool cmp(int *i,int *j){
	return (*i)<(*j);
}
int main()
{
	sieve();
	char s[200000];
	int a[10100],num;
	while (gets(s)!=NULL){
		num=0;
		int x=0;
		for (int i=0;s[i];i++){
			if (s[i]<='9'&&s[i]>='0')
				x=x*10+s[i]-48;
			else{
				a[num++]=x;
				x=0;
			}
		}
		a[num++]=x;
		long long ans=0,sum=0;
		for (int i=0;i<num;i++)
			if (p[a[i]]){
				sum=a[i++];
				while (i<num&&p[a[i]]&&a[i-1]<a[i]){
					sum+=a[i];
					i++;
				}
				if (sum>ans)
					ans=sum;
				i--;
			}
		printf("%lld\n",ans);
	}
}

/*
1 3 5 7 7 9 11
199 299 399 499 599 699 799 899 999
*/
