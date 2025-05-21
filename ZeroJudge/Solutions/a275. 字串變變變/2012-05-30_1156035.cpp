#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

    char a[1000000];
    int k,asc[127],t;
int main()
{
   while(gets(a))
   {  
      for(k=33;k<=126;k++)
        asc[k]=0;
      if(strcmp(a,"STOP!!")==0)
         break;
int len=strlen(a);
      for(k=0;k<len;k++)
         asc[a[k]]++;
      gets(a);
      for(k=0;k<len;k++)
         asc[a[k]]--;
      t=1;
      for(k=33;k<=126;k++)
         if(asc[k]!=0)
            t=0;
      if(t)
         puts("yes");
      else
         puts("no");
   }   
   return 0;
}
