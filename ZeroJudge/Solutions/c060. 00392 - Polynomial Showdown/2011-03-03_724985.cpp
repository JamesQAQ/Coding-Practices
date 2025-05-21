#include <iostream>
using namespace std;

struct Node{int x,n;} a[9];
void del(Node a[],int at,int num)
{
   for (int i=at;i<num;i++)
      a[i]=a[i+1];
}
void print(Node i)
{
   if (i.x==-1)
      cout<<"-";
   else if (i.x!=1||(i.x==1&&i.n==0))
      cout<<i.x;
   if (i.n>0)  
      cout<<"x";
   if (i.n>1)
      cout<<"^"<<i.n;
}
int main()
{
   int num;
   while (cin>>a[0].x)
   {
      num=9;
      a[0].n=8;
      for (int i=1;i<9;i++)
      {
         cin>>a[i].x;
         a[i].n=8-i;
      }
      while (num>0)
      {
         if (a[0].x!=0)
            break;
         else
         {
            num--;
            del(a,0,num);
         }
      }
      if (num==0)
      {
         cout<<"0"<<endl;
         continue;
      }
      print(a[0]);
      for (int i=1;i<num;i++)
      {
         if (a[i].x==0)
            continue;
         if (a[i].x>0)
            cout<<" + ";
         else
         {
            cout<<" - ";
            a[i].x=-a[i].x;
         }
         print(a[i]);
      }
      cout<<endl;
   }   
   return 0;
}
