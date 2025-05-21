#include <stdio.h>

int input[100000];

int binarysearch(int a[], int n, int x){
    int l = 0, r = n -1;
    while (l <= r){
        int mid = (l + r) / 2;
        if (a[mid] > x)
            r = mid - 1;
        else if (a[mid] < x)
            l = mid + 1;
        else
            return mid + 1;
    }
    return 0;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &input[i]);
    int v;
    while (m--){
        scanf("%d", &v);
        printf("%d\n", binarysearch(input, n, v));
    }
}
