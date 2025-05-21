#include <cstdio>
#include <algorithm>

int n,m,v[88],tmpv;
bool ans[88];
struct Node{
	int x,y;
} map[88][20],tmp[20],now;
int dis(Node a,Node b){
	int x=a.x-b.x,y=a.y-b.y;
	return x*x+y*y;
}
int cross(Node o,Node a,Node b){
	int ax=a.x-o.x,ay=a.y-o.y,bx=b.x-o.x,by=b.y-o.y;
	return ax*by-bx*ay;
}
bool cmp(Node i,Node j){
	int c=cross(now,i,j);
	if (c==0)
		return dis(now,i)<dis(now,j);
	else
		return c>0;
}
bool angle(Node o,Node a,Node b,Node oo,Node oa,Node ob){
	int ax=a.x-o.x,ay=a.y-o.y,bx=b.x-o.x,by=b.y-o.y;
	long long c=ax*bx+ay*by;
	long long d=(long long)dis(o,a)*dis(o,b);
	int oax=oa.x-oo.x,oay=oa.y-oo.y,obx=ob.x-oo.x,oby=ob.y-oo.y;
	long long oc=oax*obx+oay*oby;
	long long od=(long long)dis(oo,oa)*dis(oo,ob);
	c*=c,oc*=oc;
	//printf("%lld %lld %lld %lld\n",c,d,oc,od);
	return c*od==d*oc;
}
bool same(Node a[],int numa,int oa,Node b[],int numb,int ob){
	Node ta[20],tb[20];
	int tmpnum=0;
	for (int i=0;i<numa;i++)
		if (i!=oa)
			ta[tmpnum++]=a[i];
	now=a[oa];
	std::stable_sort(ta,ta+numa-1,cmp);
	tmpnum=0;
	for (int i=0;i<numb;i++)
		if (i!=ob)
			tb[tmpnum++]=b[i];
	now=b[ob];
	std::stable_sort(tb,tb+numb-1,cmp);
	long long da=dis(a[oa],ta[0]),db=dis(b[ob],tb[0]);
	//printf("%lld %lld\n",da,db);
	for (int i=1;i<numa-1;i++){
		long long dda=dis(a[oa],ta[i]),ddb=dis(b[ob],tb[i]);
		if (da*ddb!=db*dda){
			//puts("= =");
			return false;
		}
		if (!angle(a[oa],ta[i-1],ta[i],b[ob],tb[i-1],tb[i])){
			//printf("= =? %d\n",i);
			return false;	
		}
	}
	return true;
}
bool match(int x){
	for (int i=0;i<v[x];i++)
		if (same(map[x],v[x],i,tmp,tmpv,0))
			return true;
	return false;
}
int input(){
	char c=getchar();
	while (c!='-'&&(c>'9'||c<'0')) c=getchar();
	bool negative=(c=='-');
	int x=(negative)?0:c-48;
	c=getchar();
	while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
	return (negative)?-x:x;
}
int main()
{
	int cases;
	cases=input();
	while (cases--){
		n=input();
		for (int i=0;i<n;i++){
			ans[i]=false;
			v[i]=input();
			for (int j=0;j<v[i];j++)
				map[i][j].x=input(),map[i][j].y=input();
		}
		m=input();
		for (int i=0;i<m;i++){
			tmpv=input();
			for (int j=0;j<tmpv;j++)
				tmp[j].x=input(),tmp[j].y=input();
			for (int j=0;j<n;j++)
				if (v[j]==tmpv&&match(j))
					ans[j]=true;
		}
		bool one=false;
		for (int i=0;i<n;i++)
			if (ans[i]){
				if (!one) one=true;
				else putchar(' ');
				printf("%d",i+1);
			}
		if (!one)
			printf("so sad");
		puts("");
	}
}
