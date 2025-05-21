import java.util.Scanner;

public class a104{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int n, a[];
		a = new int[1000];
		MergeSort ms = new MergeSort();
		while (sc.hasNext()){
			n = sc.nextInt();
			for (int i=0; i<n; i++)
				a[i] = sc.nextInt();
			ms.sort(0,n-1,a);
			for (int i=0; i<n; i++)
				System.out.printf((i>0)?" %d":"%d",a[i]);
			System.out.printf("\n");
		}
	}
}

class MergeSort{
	int b[] = new int[1000];
	public void sort(int l,int r,int a[])	{
		if (l==r)
			return;
		int mid = (l + r) / 2;
		sort(l, mid, a);
		sort(mid+1, r, a);
		for (int i=l; i<=r; i++)
			b[i] = a[i];
		int atl = l, atr = mid + 1;
		for (int i=l; i<=r; i++){
			if (atr == r+1 || (atl <= mid && b[atl] < b[atr]))
				a[i] = b[atl++];
			else
				a[i] = b[atr++];
		}
	}
}
