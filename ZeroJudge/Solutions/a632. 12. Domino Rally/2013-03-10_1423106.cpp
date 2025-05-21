#include <cstdio>

int L[30][2],R[30][2],num;
void init(){
	for (int i=0;i<=6;i++)
		for (int j=i;j<=6;j++){
			L[num][0]=i;
			R[num][0]=j;
			L[num][1]=j;
			R[num][1]=i;
			num++;
		}
}
int Q[256],no[100],c[100];
bool cut(){
	for (int i=0;i<num-1;i++){
		//printf("%d-%d\n",R[no[i]][Q[c[i]]],L[no[i+1]][Q[c[i+1]]]);
		if (R[no[i]][Q[c[i]]]==L[no[i+1]][Q[c[i+1]]]){
			num-=2;
			for (int j=i;j<num;j++)
				no[j]=no[j+2],c[j]=c[j+2];
			return true;
		}
	}
	return false;
}
int main()
{
	Q['F']=0;
	Q['B']=1;
	init();
	while (scanf("%d %c",&no[0],&c[0])==2){
		no[0]--;
		num=1;
		while (scanf("%d %c",&no[num],&c[num])){
			if (no[num]==0&&c[num]=='F')
				break;
			no[num]--;
			num++;
			//printf("num %d\n",num);
		}
		while (num>=2){
			if (!cut())
				break;
		}
		if (num==0)
			puts("DATASET CLEARED");
		else{
			for (int i=0;i<num;i++)
				printf((i)?" %d":"%d",no[i]+1);
			puts("");
		}
	}
}
