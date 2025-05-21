import java.util.Scanner;

public class d712{
	public static void main(String args[]){
		DParray DP=new DParray();
		DP.init();
		SegmentTree ST=new SegmentTree();
		ST.init(1,1,1000000,DP);
		MAX max=new MAX();
		Scanner sc=new Scanner(System.in);
		int a,b;
		while (sc.hasNext()){
			a=sc.nextInt();
			b=sc.nextInt();
			System.out.println(a + " " + b + " " + ST.query(1,1,1000000,max.min(a,b),max.max(a,b)));
		}
	}
}
class MAX{
	public int max(int a,int b){
		return (a>b)?a:b;
	}
	public int min(int a,int b){
		return (a<b)?a:b;
	}
}
class SegmentTree{
	int a[]=new int[4000001];
	MAX max=new MAX();
	public void init(int at,int l,int r,DParray v){
		if (l==r){
			a[at]=v.dp[l];
			return;
		}
		int mid=(l+r)/2;
		init(2*at,l,mid,v);
		init(2*at+1,mid+1,r,v);
		a[at]=max.max(a[2*at],a[2*at+1]);
	}
	public int query(int at,int l,int r,int dl,int dr){
		if (dl<=l&&r<=dr)
			return a[at];
		int mid=(l+r)/2,maxx=0;
		if (dl<=mid)
			maxx=max.max(maxx,query(2*at,l,mid,dl,dr));
		if (dr>=mid+1)
			maxx=max.max(maxx,query(2*at+1,mid+1,r,dl,dr));
		return maxx;
	}
}
class DParray{
	int dp[]=new int[1000001];
	boolean run[]=new boolean[1000001];
	private int DP(long x){
		if (x>1000000)
			return ((x%2==1)?DP(3*x+1):DP(x/2))+1;
		if (!run[(int)x]){
			dp[(int)x]=((x%2==1)?DP(3*x+1):DP(x/2))+1;
			run[(int)x]=true;
		}
		return dp[(int)x];
	}
	public void init(){
		for (int i=1;i<=1000000;i++)
			run[i]=false;
		dp[1]=1;
		run[1]=true;
		for (int i=1;i<=1000000;i++)
			DP(i);
	}
}
