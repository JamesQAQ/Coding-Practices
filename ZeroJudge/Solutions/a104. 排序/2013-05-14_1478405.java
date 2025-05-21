import java.util.Scanner;

public class a104_2{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int n, a[];
		a = new int[1000];
		//MergeSort ms = new MergeSort();
		while (sc.hasNext()){
			n = sc.nextInt();
			for (int i=0; i<n; i++)
				a[i] = sc.nextInt();
			//ms.sort(0,n-1,a);
			int tmp;
			for (int i=0; i<n; i++)
				for (int j=i; j<n; j++)
					if (a[i] > a[j]){
						tmp = a[i];
						a[i] = a[j];
						a[j] = tmp;
					}
			for (int i=0; i<n; i++)
				System.out.printf((i>0)?" %d":"%d",a[i]);
			System.out.printf("\n");
		}
	}
}
