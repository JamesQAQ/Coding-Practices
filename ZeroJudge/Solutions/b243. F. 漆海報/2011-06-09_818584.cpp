#include <cstdio>
#include <iostream>

struct Node {int x[2],y[2];} area[500];
int main()
{
    int cases,n,eps=1<<15,nox[70000],noy[70000],dx[1000],dy[1000],numx,numy;
    scanf("%d",&cases);
    while (cases--){
        bool ux[70000]={},uy[70000]={},cover[1000][1000]={};
        scanf("%d",&n);
        for (int i=0;i<n;i++){
            scanf("%d %d %d %d",&area[i].x[0],&area[i].y[0],&area[i].x[1],&area[i].y[1]);
            if (area[i].x[0]>area[i].x[1])
                std::swap(area[i].x[0],area[i].x[1]);
            if (area[i].y[0]>area[i].y[1])
                std::swap(area[i].y[0],area[i].y[1]);
            area[i].x[0]+=eps;
            area[i].x[1]+=eps;
            area[i].y[0]+=eps;
            area[i].y[1]+=eps;
            ux[area[i].x[0]]=ux[area[i].x[1]]=uy[area[i].y[0]]=uy[area[i].y[1]]=true;
        }
        numx=numy=0;
        for (int i=0;i<70000;i++)
            if (ux[i])
                nox[i]=numx,dx[numx++]=i;
        for (int i=0;i<70000;i++)
            if (uy[i])
                noy[i]=numy,dy[numy++]=i;
        for (int i=0;i<n;i++)
            for (int j=nox[area[i].x[0]];j<nox[area[i].x[1]];j++)
                for (int k=noy[area[i].y[0]];k<noy[area[i].y[1]];k++)
                    cover[j][k]=true;
        long long ans=0;
        for (int i=0;i<numx;i++)
            for (int j=0;j<numy;j++)
                if (cover[i][j])
                    ans+=(long long)(dx[i+1]-dx[i])*(dy[j+1]-dy[j]);
        printf("%lld\n",ans);
    }
    return 0;
}
