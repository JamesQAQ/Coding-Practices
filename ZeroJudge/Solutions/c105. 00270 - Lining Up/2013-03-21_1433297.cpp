#include <cstdio>
#include <algorithm>

int x[1000],y[1000];
bool first=true;
char s[1000];
int t[1000],t2[1000],now;
int cross(int o,int a,int b){
	int ax=x[a]-x[o],ay=y[a]-y[o];
	int bx=x[b]-x[o],by=y[b]-y[o];
	return ax*by-bx*ay;
}
bool cmp(int i,int j){
	return cross(now,i,j)>=0;
}
int work(int n){
	int ans=1;
	for (int i=0;i<n;i++){
		int num=0,num2=0;
		now=i;
		for (int j=0;j<n;j++)
            if (i!=j){
            	if (y[j]>y[i]||(y[j]==y[i]&&x[j]>x[i]))
					t[num++]=j;
            	else
                    t2[num2++]=j;
        	}
		std::stable_sort(t,t+num,cmp);
        std::stable_sort(t2,t2+num2,cmp);
		for (int j=0;j<num;j++){
			int k=j,sum=1;
			while (k<num&&(x[i]-x[t[j]])*(y[i]-y[t[k]])==(x[i]-x[t[k]])*(y[i]-y[t[j]]))
				k++,sum++;
			if (sum>ans)
				ans=sum;
			j=k-1;
		}
        for (int j=0;j<num2;j++){
			int k=j,sum=1;
			while (k<num2&&(x[i]-x[t2[j]])*(y[i]-y[t2[k]])==(x[i]-x[t2[k]])*(y[i]-y[t2[j]]))
				k++,sum++;
			if (sum>ans)
				ans=sum;
			j=k-1;
		}
	}
	return ans;
}
int main()
{
	int cases,num;
	gets(s);
	while (gets(s)!=NULL){
		if (s[0]=='\0'){
			if (first) first=false;
			else printf("%d\n\n",work(num));
			num=0;
		}
		else{
			sscanf(s,"%d %d",&x[num],&y[num]);
			num++;
		}
	}
	printf("%d\n",work(num));
}
