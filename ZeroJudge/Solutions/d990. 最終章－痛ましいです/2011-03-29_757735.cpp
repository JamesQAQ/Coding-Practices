#include <iostream>
#include <algorithm>
using namespace std;

char p[100001],s[100001];
int len,lenp,t[100000],lensub[100000];
bool cmp(int i,int j){
    int mini=min(lensub[i],lensub[j]);
    for (int k=0;k<=mini;k++){
        if (s[k+i]<s[k+j]) return 1;
        if (s[k+i]>s[k+j]) return 0;
    }
    return i>j;
}
int search_down(int l,int r,int at,int down,int up){
    int mid,temp;
    while (l<=r){
        mid=(l+r)/2;
        temp=t[mid];
        if (at>=lensub[temp]){
            l=mid+1;
            continue;
        }
        char pv=p[at],v=s[at+temp];
        if (pv>v) l=mid+1;
        else if (pv<v) r=mid-1;
        else{
            if (mid-1>=down&&at<lensub[t[mid-1]]){
                if (s[t[mid-1]+at]==pv) r=mid-1;
                else return mid;
            }
            else return mid;
        }
    }
    return -1;
}
int search_up(int l,int r,int at,int down,int up){
    int mid,temp;
    while (l<=r){
        mid=(l+r)/2;
        temp=t[mid];
        if (at>=lensub[temp]){
            l=mid+1;
            continue;
        }
        char pv=p[at],v=s[at+temp];
        if (pv>v) l=mid+1;
        else if (pv<v) r=mid-1;
        else{
            if (mid+1<=up&&at<lensub[t[mid+1]]){
                if (s[t[mid+1]+at]==pv) l=mid+1;
                else return mid;
            }
            else return mid;
        }
    }
    return -1;
}
int count(){
    int down=0,up=len-1,tdown,tup;
    for (int i=0;i<lenp;i++){
        tdown=search_down(down,up,i,down,up);
        tup=search_up(down,up,i,down,up);
        if (tdown!=-1&&tup!=-1&&tdown<=tup)
            up=tup,down=tdown;
        else return 0;
    }
    return up-down+1;
}
int main(){
    int n;
    scanf("%s",s);
    len=strlen(s);
    for (int i=0;i<len;i++){
        lensub[i]=len-i;
        t[i]=i;
    }
    stable_sort(t,t+len,cmp);
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%s",p);
        lenp=strlen(p);
        printf("%d\n",count());
    }
    return 0;
}
