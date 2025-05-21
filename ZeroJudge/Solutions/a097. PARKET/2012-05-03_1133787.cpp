#include <cstdio>

bool ok(int R,int l,int B){
    int w=R/l,d=w-l,left=0,righ=25000,mid;
    //printf("l %d w %d\n",l,w);
    while (left<=righ){
        mid=(left+righ)/2;
        //printf("mid %d\n",mid);
        long long v=(long long)(l+2*mid)*(w+2*mid)-R;
        if (v>B)
            righ=mid-1;
        else if (v<B)
            left=mid+1;
        else{
            printf("%d %d\n",w+2*mid,l+2*mid);
            return true;
        }
    }
    return false;
}
int main()
{
    int B,R;
    while (scanf("%d %d",&B,&R)==2){
        for (int i=1;i*i<=R;i++)
            if (R%i==0)
                if (ok(R,i,B))
                    break;
    }
}
