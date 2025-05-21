#include <cstdio>
#include <algorithm>

int n;
unsigned long long score[100000],*p[100000];
unsigned long long input(){
    char c=getchar();
    while (c>'9'||c<'0') c=getchar();
    unsigned long long x=c-48;
    while (c<='9'&&c>='0') x=x*10+c-48,c=getchar();
    return x;
}
bool cmp(unsigned long long *i,unsigned long long *j){
    return (*i)>(*j);
}
int tree[100000];
int search(int x){
    int sum=0;
    while (x>0){
        sum+=tree[x];
        x-=x&(-x);
    }
    return sum;
}
void insert(int x){
    while (x<=n){
        tree[x]++;
        x+=x&(-x);
    }
}
int main()
{
    while (scanf("%d",&n)==1){
        for (int i=0;i<n;i++)
            score[i]=input(),p[i]=&score[i],tree[i+1]=0;
        std::stable_sort(p,p+n,cmp);
        for (int i=0;i<n;i++)
            (*p[i])=i+1;
        for (int i=0;i<n;i++){
            printf("%d\n",search(score[i]-1)+1);
            insert(score[i]);
        }
    }
}
