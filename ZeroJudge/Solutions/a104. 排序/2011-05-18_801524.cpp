#include <cstdio>

void merge(int l,int mid,int r,int a[]){
   int lnum=mid-l+1,rnum=r-mid,left[lnum+1],righ[rnum+1];
   for (int i=0;i<lnum;i++)
      left[i]=a[l+i];
   for (int i=0;i<rnum;i++)
      righ[i]=a[mid+1+i];
   left[lnum]=righ[rnum]=2147483647;
   int ld=0,rd=0;
   for (int i=0;i<r-l+1;i++){
      if (left[ld]<righ[rd])
         a[l+i]=left[ld++];
      else
         a[l+i]=righ[rd++];
   }
}
void merge_sort(int l,int r,int a[]){
   if (l==r)
      return;
   int mid=(l+r)/2;
   merge_sort(l,mid,a);
   merge_sort(mid+1,r,a);
   merge(l,mid,r,a);
}
int main()
{
   int a[1000],n;
   while (scanf("%d",&n)==1){
      for (int i=0;i<n;i++)
         scanf("%d",&a[i]);
      merge_sort(0,n-1,a);
      printf("%d",a[0]);
      for (int i=1;i<n;i++)
         printf(" %d",a[i]);
      puts("");
   }
   return 0;
}
