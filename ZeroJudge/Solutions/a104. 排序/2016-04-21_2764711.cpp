#include <stdio.h>
#include <iostream>

using std::swap;

#define MAX 10000
int a[MAX];

void quicksort(int a[], int l, int r){
    if (l >= r)
        return;
    int pivot = a[l], pos = l;
    for (int i = r; i > pos; i--){
        if (a[i] < pivot){
            swap(a[pos + 1], a[i]);
            pos++;
            i++;
        }
    }
    swap(a[l], a[pos]);
    quicksort(a, l, pos - 1);
    quicksort(a, pos + 1, r);
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1){
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        quicksort(a, 0, n - 1);
        for (int i = 0; i < n; i++)
            printf((i)? " %d" : "%d", a[i]);
        puts("");
    }
}
